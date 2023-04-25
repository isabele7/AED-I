#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void Intercala(int p, int q, int r, int v[]) { 
  int i, j, k, *w;
  w = malloc((r - p) * sizeof(int)); 
  i = p;
  j = q;
  k = 0; 
  while (i < q && j < r) { 
    if (v[i] <= v[j])
      w[k++] = v[i++]; 
    else
      w[k++] = v[j++]; 
  } 
  while (i < q)
    w[k++] = v[i++]; 
  while (j < r)
    w[k++] = v[j++]; 
  for (i = p; i < r; i++)
    v[i] = w[i - p];
  free(w);
}

void Mergesort(int p, int r, int v[]) { 
  if (p < r - 1) {
    int q = (p + r) / 2; 
    Mergesort(p, q, v); 
    Mergesort(q, r, v); 
    Intercala(p, q, r, v); 
  } 
}

int main() {
    int n = 10000, i, v[n];
    for (i = 0; i < n; i++) {
        v[i] = rand();
    }
    clock_t start, end;
    double cpu_time_used;
    start = clock(); 
    Mergesort(0, n, v);
    end = clock();
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC; 
    printf("Tempo de execução: %f milissegundos\n", cpu_time_used * 1000);
    return 0;
}
