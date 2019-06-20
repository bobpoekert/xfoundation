#pragma once

#include <stdint.h>
#include <stdlib.h>
#include <string.h>

typedef struct XF_Buffer_Chunk {

    size_t element_size;
    size_t start_idx;
    size_t end_idx;
    size_t max_size;
    struct XF_Buffer_Chunk *next;

} XF_Buffer_Chunk;

typedef struct XF_Buffer_Queue {

    XF_Buffer_Chunk *head;
    XF_Buffer_Chunk *tail;
    size_t size;
    size_t pool_size;
    size_t max_pool_size;
    size_t element_size;
    size_t chunk_size;

} XF_Buffer_Queue;


XF_Buffer_Queue *xf_buffer_queue_create(size_t element_size, size_t chunk_size, size_t pool_size);
void xf_buffer_queue_free(XF_Buffer_Queue *q);
void xf_buffer_queue_append(XF_Buffer_Queue *q, void *v);
char xf_buffer_queue_take(XF_Buffer_Queue *q, void *target);