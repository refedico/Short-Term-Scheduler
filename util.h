#ifndef UTIL
#define UTIL
#include <stdio.h>
#define PROCLEN 20

typedef struct process{
    char nome[PROCLEN];
    long burst_cpu;
    long priority;
    long perm_burst;
}proc_t;


int compareBurst(const void* a, const void* b);
int comparePriority(const void* a, const void* b);
float printBurst(proc_t* in, unsigned n);

/*
void swapI(proc_t* a, proc_t* b)
long compareBurst(proc_t* a, proc_t* b)
long comparePriority(proc_t* a, proc_t* b)
void sort(proc_t* a, unsigned n, long(*compare)(proc_t*,proc_t*))
*/

#endif
