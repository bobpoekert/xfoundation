#pragma once

#include <stdint.h>
#include <stdlib.h>
#include <string.h>

typedef struct XF_Buffer_Queue {

    void **front_buffer;
    void **back_buffer;
    size_t front_buffer_size;
    size_t back_buffer_size;
    size_t max_size;

} XF_Buffer_Queue;


XF_Buffer_Queue *xf_buffer_queue_create(size_t buffer_size);
#define xf_buffer_queue_free free
void xf_buffer_queue_append(XF_Buffer_Queue *q, void *v);
void xf_buffer_queue_swap(XF_Buffer_Queue *q);
void *xf_buffer_queue_take(XF_Buffer_Queue *q);