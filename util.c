#include "util.h"

int compareBurst(const void* a, const void* b){
    proc_t* A = (proc_t*)a;
    proc_t* B = (proc_t*)b;
    return A->burst_cpu - B->burst_cpu;
}

int comparePriority(const void* a, const void* b){
    proc_t* A = (proc_t*)a;
    proc_t* B = (proc_t*)b;
    return A->priority - B->priority;
}

float printBurst(proc_t* in, unsigned n){
    float wait = 0;
    for (unsigned i = 0; i < n; i++) {
    printf("%s ", in[i].nome);
    wait = wait + in[i].burst_cpu * (n - i - 1);
  }
  return wait/n;
}

/*
void swapI(proc_t* a, proc_t* b){
    proc_t c = *b;
    *b = *a;
    *a = c;
}

long compareBurst(proc_t* a, proc_t* b){
    return a->burst_cpu - b->burst_cpu;
}

long comparePriority(proc_t* a, proc_t* b){
    return a->priority - b->priority;
}

void sort(proc_t* a, unsigned n, long(*compare)(proc_t*,proc_t*)){
    short swap = 1;
    n--;
    while (swap){
        swap = 0;
        for (unsigned i = 0; i < n; i++){
            if (compare(&a[i],&a[i+1]) > 0) {
                swapI(&a[i],&a[i+1]);
                swap = 1;
            }
        }
        n--;
    }
}
*/
