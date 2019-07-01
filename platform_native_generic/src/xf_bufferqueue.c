#include <xf_bufferqueue.h>

XF_Buffer_Queue *xf_buffer_queue_create(size_t buffer_size) {
    size_t buffer_size_bytes = sizeof(void *) * buffer_size;
    XF_Buffer_Queue *res = malloc(sizeof(XF_Buffer_Queue) + (buffer_size_bytes * 2));
    if (!res) return 0;
    res->front_buffer = (void **) (res + sizeof(XF_Buffer_Queue));
    res->back_buffer = res->front_buffer + buffer_size_bytes;
    res->front_buffer_size = 0;
    res->back_buffer_size = 0;
    res->max_size = buffer_size;
    return res;
}

void xf_buffer_queue_append(XF_Buffer_Queue *q, void *v) {
    /* TODO: silently drop items if queue is full. probably fine for input events */
    if (q->back_buffer_size >= q->max_size) return;

    q->back_buffer[q->back_buffer_size] = v;
    q->back_buffer_size++;
}

void xf_buffer_queue_swap(XF_Buffer_Queue *q) {
    q->front_buffer_size = q->back_buffer_size;
    void *old_front_buffer = q->front_buffer;
    q->front_buffer = q->back_buffer;
    q->back_buffer = old_front_buffer;
    q->back_buffer_size = 0;
}

void *xf_buffer_queue_take(XF_Buffer_Queue *q) {
    if (q->front_buffer_size < 1) return 0;
    void *res = q->front_buffer[q->max_size - q->front_buffer_size];
    q->front_buffer_size--;
    return res;
}