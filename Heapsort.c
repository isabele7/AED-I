#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void SacodeHeap (int m, int v[]){
  int t, f = 2;
  while(f <= m){
    if(f < m && v[f] < v[f+1])
      ++f;
    if(v[f/2] >= v[f])
      break;
    t = v[f/2];
    v[f/2] = v[f];
    v[f] = t;
    f *= 2;
  }
}

void Heapsort (int n, int v[]){
  int m;
  for( m = 1; m < n; m++)
    SacodeHeap (m,v);
  for (m = n; m > 1; m--){
    int t = v[1];
    v[1] = v[m];
    v[m] = t;
    SacodeHeap (m-1, v);
  }
}

int main() {
    int n = 20000, i, v[n];
    for (i = 0; i < n; i++) {
        v[i] = rand();
    }
    clock_t start, end;
    double cpu_time_used;
    start = clock(); 
    Heapsort(n, v);
    end = clock();
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC; 
    printf("Tempo de execução: %f milissegundos\n", cpu_time_used * 1000);
    return 0;
}
