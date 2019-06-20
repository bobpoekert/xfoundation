
#include <xf_bufferqueue.h>

#define xf_buffer_chunk_data(c) (c + sizeof(XF_Buffer_Chunk))
#define xf_buffer_chunk_elem(c, idx) (c + (sizeof(XF_Buffer_Chunk) * idx))

#define xf_buffer_queue_pool(q) ((XF_Buffer_Chunk **) (q + sizeof(XF_Buffer_Queue)))
#define xf_buffer_queue_pool_elem(q, idx) (xf_buffer_queue_pool(q)[idx])


XF_Buffer_Chunk *xf_buffer_chunk_create(XF_Buffer_Queue *owner) {
    XF_Buffer_Chunk *res;
    if (owner->pool_size > 0) {
        res = xf_buffer_queue_pool_elem(owner, owner->pool_size);
        owner->pool_size--;
        res->start_idx = 0;
        res->end_idx = 0;
    } else {
        res = malloc(sizeof(XF_Buffer_Chunk)) + (owner->element_size * owner->chunk_size);
        if (!res) return 0;
        res->element_size = owner->element_size;
        res->max_size = owner->chunk_size;
        res->start_idx = 0;
        res->end_idx = 0;
    }
    return res;
}

void xf_buffer_queue_add_chunk(XF_Buffer_Queue *q) {
    XF_Buffer_Chunk *c = xf_buffer_chunk_create(q);
    if (q->tail) {
        q->tail->next = c;
        q->tail = c;
    } else {
        q->head = c;
        q->tail = c;
    }
}

XF_Buffer_Queue *xf_buffer_queue_create(size_t element_size, size_t chunk_size, size_t pool_size) {
    XF_Buffer_Queue *res = malloc(sizeof(XF_Buffer_Queue) + (sizeof(XF_Buffer_Chunk *) * pool_size));
    if (!res) return 0;
    res->element_size = element_size;
    res->chunk_size = chunk_size;
    res->max_pool_size = pool_size;
    res->pool_size = 0;
    res->head = 0;
    res->tail = 0;
    xf_buffer_queue_add_chunk(res);
    return res;
}

void xf_buffer_chunk_free(XF_Buffer_Queue *q, XF_Buffer_Chunk *c) {
    if (q->pool_size < q->max_pool_size) {
        q->pool_size++;
        xf_buffer_queue_pool_elem(q, q->pool_size) = c;
    } else {
        free(c);
    }
}

void xf_buffer_queue_free(XF_Buffer_Queue *q) {
    XF_Buffer_Chunk *head = q->head;
    XF_Buffer_Chunk *next;
    while(head != q->tail) {
        next = head->next;
        free(head);
        head = next;
    }

    for (size_t i=0; i < q->pool_size; i++) {
        free(xf_buffer_queue_pool_elem(q, i));
    }

    free(q);
}

char xf_buffer_chunk_is_full(XF_Buffer_Chunk *c) {
    size_t off = (c->end_idx + c->element_size);
    return (off > c->start_idx) || (off > c->max_size);
}

char xf_buffer_queue_is_full(XF_Buffer_Queue *q) {
    return !(q->tail) || xf_buffer_chunk_is_full(q->tail);
}

void xf_buffer_chunk_append(XF_Buffer_Chunk *c, void *v) {
    size_t old_end = c->end_idx;
    c->end_idx++;
    memcpy(xf_buffer_chunk_elem(c, old_end), v, c->element_size);
}

void xf_buffer_queue_append(XF_Buffer_Queue *q, void *v) {
    if (xf_buffer_queue_is_full(q)) {
        xf_buffer_queue_add_chunk(q);
    }
    xf_buffer_chunk_append(q->tail, v);
    q->size++;
}

size_t xf_buffer_chunk_size(XF_Buffer_Chunk *c) {
    if (c->end_idx == c->start_idx) {
        return 0;
    } else if (c->end_idx > c->start_idx){
        return c->end_idx - c->start_idx;
    } else {
        return (c->max_size - c->start_idx) + c->end_idx;
    }
}

void xf_buffer_chunk_take(XF_Buffer_Chunk *c, void *target) {
    if (c->end_idx == 0) {
        c->end_idx = c->max_size;
    }
    size_t old_idx = c->end_idx;
    c->end_idx--;
    void *res = malloc(c->element_size);
    memcpy(target, xf_buffer_chunk_elem(c, old_idx), c->element_size);
}

char xf_buffer_queue_take(XF_Buffer_Queue *q, void *target) {
    if (q->size < 1 || !(q->head)) {
        return 0;
    }
    xf_buffer_chunk_take(q->head, target);
    q->size--;
    if (xf_buffer_chunk_size(q->head) < 1) {
        XF_Buffer_Chunk *old_head = q->head;
        q->head = q->head->next;
        xf_buffer_chunk_free(q, old_head);
    }
    return 1;
}