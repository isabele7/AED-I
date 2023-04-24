#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void Selecao(int n, int v[]){
  int i,j,min,x;
  for(i = 0; i < n-1; i++){
    min = i;
    for(j = i+1; j < n; j++)
      if(v[j] < v[min])
        min = j;
    x = v[i];
    v[i] = v[min];
    v[min] = x;
  }
}

int main() {
    int n = 5000, i, v[n];
    for (i = 0; i < n; i++) {
        v[i] = rand();
    }
    clock_t start, end;
    double cpu_time_used;
    start = clock(); 
    Selecao(n, v);
    end = clock();
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC; 
    printf("Tempo de execução: %f milissegundos\n", cpu_time_used * 1000);
    return 0;
}
