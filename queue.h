#ifndef QUEUE
#define QUEUE
#include "util.h"

typedef struct Queue {
  proc_t **procs;
  unsigned head;
  unsigned tail;
  unsigned maxsize;
  unsigned actualsize;
} Queue_t;

Queue_t *initQueue(size_t len);
void pushQueue(Queue_t *Q, proc_t *el);
proc_t *popQueue(Queue_t *Q);
void freeQueue(Queue_t *Q);

#endif
