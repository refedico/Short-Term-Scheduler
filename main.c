#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utils.h"

int main(int argc, char* argv[])
{

  FILE* fd;
  int n;
  int quanto;
  char i;
  float wait = 0;

  fd = fopen(argv[1], "r");
  if (fd == NULL) {
    perror("Errore in apertura del file, esegui facendo ./a.out input.txt");
    exit(1);
  }

  fscanf(fd, "%c %d %d", &i, &n, &quanto);

  process* v_mod = malloc(n * sizeof(process));
  process* v = malloc(n * sizeof(process));

  for (int i = 0; i < n; i++) {
    fscanf(fd, "%s %d %d", &v[i].nome, &v[i].burst_cpu, &v[i].priority);
  }

  for (int i = 0; i < n; i++) {
    printf("%s %d %d\n", v[i].nome, v[i].burst_cpu, v[i].priority);
  }

  // Una copia immodificata del vettore per il Round Robin
  for (int i = 0; i < n; i++) {
    strcpy(v_mod[i].nome, v[i].nome);
    v_mod[i].burst_cpu = v[i].burst_cpu;
    v_mod[i].priority = v[i].priority;
  }

  // First Come First Serve
  printf("\n\nFCFS ordine di esecuzione: ");
  for (int i = 0; i < n; i++) {
    printf("%s ", v[i].nome);
    wait = wait + v[i].burst_cpu * (n - i - 1);
  }
  wait = wait / n;
  printf("\nTempo medio di attesa: ");
  printf("%f \n", wait);

  wait = 0;

  // Shortest Job First
  sort_SJF(v, n); // per ordinare in base al burst

  printf("SJF ordine di esecuzione: ");
  for (int i = 0; i < n; i++) {
    printf("%s ", v[i].nome);
    wait = wait + v[i].burst_cpu * (n - i - 1);
  }
  wait = wait / n;
  printf("\nTempo medio di attesa: ");
  printf("%f \n", wait);

  wait = 0;

  // Priority
  sort_priority(v, n); // per ordinare in base alla priority

  printf("Priority ordine di esecuzione: ");
  for (int i = 0; i < n; i++) {
    printf("%s ", v[i].nome);
    wait = wait + v[i].burst_cpu * (n - i - 1);
  }
  wait = wait / n;
  printf("\nTempo medio di attesa: ");
  printf("%f \n", wait);

  // Round Robin
  printf("Round Robin ordine di esecuzione: ");

  for (int i = 0; i < n; i++) {
    strcpy(v[i].nome, v_mod[i].nome);
    v[i].burst_cpu = v_mod[i].burst_cpu;
    v[i].priority = v_mod[i].priority;
  }

  int cont = 0, tempo = 0, flag = 0;
  int cp[20];
  int rimasti = n;

  wait = 0;

  // copia dei burst_cpu per modificarli
  for (cont = 0; cont < n; cont++) {
    cp[cont] = v[cont].burst_cpu;
  }

  cont = 0;

  do {
    if (cp[cont] <= quanto && cp[cont] > 0) {
      tempo += cp[cont];
      printf("%s[%d] ", v[cont].nome, cp[cont]);
      cp[cont] = 0;
      flag = 1;
    } else if (cp[cont] > 0) {
      cp[cont] -= quanto;
      tempo += quanto;
      printf("%s[%d] ", v[cont].nome, quanto);
    }

    if (cp[cont] == 0 && flag == 1) {
      rimasti--;
      wait += tempo - v[cont].burst_cpu;
      flag = 0;
    }

    if (cont == n - 1)
      cont = 0;
    else if (tempo >= 0)
      cont++;

  } while (rimasti != 0);

  printf("\nTempo medio di attesa: ");
  printf("%f\n", wait / n);

  return 0;
}
