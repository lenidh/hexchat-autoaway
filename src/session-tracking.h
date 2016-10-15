#ifndef SESSION_TRACKING_H
#define SESSION_TRACKING_H

#define EVENT_SESSION_LOCK 1
#define EVENT_SESSION_UNLOCK 2

void start_tracking_session(void (*event_handler)(int));
void stop_tracking_session();

#endif // SESSION_TRACKING_H