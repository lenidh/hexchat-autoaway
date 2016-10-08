#include <stdlib.h>
#include "msg_buffer.h"

struct autoaway_msg_buffer_element {
    const char* msg;
    struct autoaway_msg_buffer_element* next;
};
static size_t ELEMENT_TSIZE = sizeof(struct autoaway_msg_buffer_element);

struct autoaway_msg_buffer {
    size_t size;
    size_t capacity;
    struct autoaway_msg_buffer_element* head;
    struct autoaway_msg_buffer_element* tail;
};
static size_t BUFFER_TSIZE = sizeof(struct autoaway_msg_buffer);

struct autoaway_msg_buffer* autoaway_msg_buffer_create(size_t capacity) {
    struct autoaway_msg_buffer* inst = malloc(BUFFER_TSIZE);
    inst->size = 0;
    inst->capacity = capacity;
    inst->head = NULL;
    inst->tail = NULL;
    return inst;
}

void autoaway_msg_buffer_delete(struct autoaway_msg_buffer* b) {
    while(autoaway_msg_buffer_dequeue(b) != NULL);
    free(b);
}

void autoaway_msg_buffer_enqueue(struct autoaway_msg_buffer* b, const char* msg) {
    if(msg == NULL) return;
    if(b->size == b->capacity) {
        struct autoaway_msg_buffer_element* dropped = b->head;
        b->head = b->head->next;
        free(dropped);
        b->size -= 1;
    }
    struct autoaway_msg_buffer_element* new = malloc(ELEMENT_TSIZE);
    new->msg = msg;
    new->next = NULL;
    if(b->head == NULL) b->head = new;
    if(b->tail != NULL) b->tail->next = new;
    b->tail = new;
    b->size += 1;
}

const char* autoaway_msg_buffer_dequeue(struct autoaway_msg_buffer* b) {
    if(b->size == 0) return NULL;
    struct autoaway_msg_buffer_element* dequeued = b->head;
    b->head = b->head->next;
    const char* msg = dequeued->msg;
    free(dequeued);
    b->size -= 1;
    return msg;
}
