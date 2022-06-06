#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "util.h"
#include "queue.h"

int main(int argc, char* argv[])
{
  argc = 2;
  FILE* fd;
  unsigned n;
  unsigned quanto;

  fd = fopen(argv[1], "r");
  if (fd == NULL) {
    perror("Errore in apertura del file, esegui facendo ./a.out input.txt");
    exit(1);
  }

  fscanf(fd, "# %d %d\n", &n, &quanto);
  Queue_t* queue = initQueue(n);
  proc_t* v = malloc(n * sizeof(proc_t));

  for (unsigned i = 0; i < n; i++) {
    proc_t* proc = (proc_t*)malloc(sizeof(proc_t));
    fscanf(fd, "%s %ld %ld", v[i].nome, &v[i].burst_cpu, &v[i].priority);
    proc->burst_cpu = v[i].burst_cpu;
    proc->perm_burst = proc->burst_cpu;
    proc->priority = v[i].priority;
    memcpy(proc->nome,v[i].nome,sizeof(proc->nome));
    pushQueue(queue,proc);
    printf("%s %ld %ld\n", v[i].nome, v[i].burst_cpu, v[i].priority);
  }

  // First Come First Serve
  printf("\n\nFCFS ordine di esecuzione: \nTempo medio di attesa: %f \n", printBurst(v,n));

  // Shortest Job First
  //sort(v, n, compareBurst); // OLD BUBBLE
  qsort(v, n, sizeof(proc_t), compareBurst);
  printf("SJF ordine di esecuzione: \nTempo medio di attesa: %f \n", printBurst(v,n));

  // Priority
  //sort(v, n, comparePriority); // OLD BUBBLE
  qsort(v, n, sizeof(proc_t), comparePriority);
  printf("Priority ordine di esecuzione: \nTempo medio di attesa: %f \n", printBurst(v,n));

  // Round Robin
  printf("Round Robin ordine di esecuzione: ");

  unsigned tempo = 0;
  float wait = 0;
 
  for(;;){
    proc_t* popped = popQueue(queue);
    if (popped == NULL){
      break;
    }
    if (popped->burst_cpu > 0){
      printf("%s[%ld] ", popped->nome, popped->burst_cpu);
      tempo += ((popped->burst_cpu > quanto) ? quanto : popped->burst_cpu);
      popped->burst_cpu -= quanto;
      pushQueue(queue,popped);
      if (popped->burst_cpu <= 0){
        wait += tempo - popped->perm_burst;
        free(popped);
      }
    }
}

printf("\nTempo medio di attesa: %f\n", wait/n);
free(v);
freeQueue(queue);
return 0;
}
