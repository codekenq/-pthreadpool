#ifndef __QUEUE_H__
#define __QUEUE_H__
#include "item.h"

/* The handle of a queue for user */
typedef struct queue *Q;
typedef Q QUEUE;

/* Fuction of destroy a queue */
void queue_dump(Q);

/* Fuction of init a queue */
Q queue_init();

/* Fuction of test a queue is empty */
int queue_empty(Q);

/* Fuction of put data in queue*/
void queue_put(Q, Item);

/* Fuction of get and pop data from queue */
Item queue_get(Q);
#endif/* __QUEUUE_H__ */
