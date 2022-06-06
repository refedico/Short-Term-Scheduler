#include "queue.h"
#include <stdlib.h>

Queue_t *initQueue(size_t len) {
  Queue_t *Q = (Queue_t *)malloc(sizeof(Queue_t));
  if (Q == NULL) {
    perror("Queue*");
    exit(1);
  }
  Q->procs = (proc_t **)malloc(sizeof(proc_t *) * len);
  if (Q->procs == NULL) {
    perror("QueueBucket");
    exit(1);
  }
  Q->maxsize = len;
  Q->head = 0;
  Q->tail = 0;
  Q->actualsize = 0;
  return Q;
}

void pushQueue(Queue_t *Q, proc_t *proc) {
  Q->procs[Q->tail] = proc;
  Q->tail = (Q->tail + 1 >= Q->maxsize) ? 0 : Q->tail + 1;
  Q->actualsize++;
}

proc_t *popQueue(Queue_t *Q) {
  if (Q->actualsize == 0){
    return NULL;
  }
  proc_t *proc = NULL;
  proc = Q->procs[Q->head];
  Q->head = (Q->head + 1 >= Q->maxsize) ? 0 : Q->head + 1;
  Q->actualsize--;
  return proc;
}

void freeQueue(Queue_t *Q) {
  free(Q->procs);
  free(Q);
}
