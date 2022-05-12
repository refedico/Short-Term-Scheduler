#ifndef HEADER_FILE
#define HEADER_FILE
 
typedef struct {
    char nome[20];
    int burst_cpu;
    int priority;
}process;
 
void sort_SJF(process a[], int n) { //nello specifico è un bubble sort
    int i = 0, j = 0;
    process tmp;
    for (i = 0; i < n; i++) {   
        for (j = 0; j < n - i - 1; j++) { 
            if (a[j].burst_cpu > a[j + 1].burst_cpu) {  
                tmp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = tmp;
            }
        }
    }
}
 
void sort_priority(process a[], int n) { //stessa bubble sort di prima ma cambiando il confronto
    int i = 0, j = 0;
    process tmp;
    for (i = 0; i < n; i++) {   
        for (j = 0; j < n - i - 1; j++) { 
            if (a[j].priority > a[j + 1].priority) {  
                tmp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = tmp;
            }
        }
    }
}
#endif
 
