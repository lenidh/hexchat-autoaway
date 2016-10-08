#ifndef MSG_BUFFER_H
#define MSG_BUFFER_H

struct autoaway_msg_buffer;
typedef struct autoaway_msg_buffer* autoaway_msg_buffer;

autoaway_msg_buffer autoaway_msg_buffer_create(size_t capacity);
void autoaway_msg_buffer_delete(autoaway_msg_buffer b);
void autoaway_msg_buffer_enqueue(autoaway_msg_buffer b, const char* msg);
const char* autoaway_msg_buffer_dequeue(autoaway_msg_buffer b);

#endif // MSG_BUFFER_H