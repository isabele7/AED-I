#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int Separa(int p, int r, int v[]) {
    int c, j, k, t;
    c = v[r];
    j = p;
    for (k = p; k < r; k++)
        if (v[k] <= c) {
            t = v[j];
            v[j] = v[k];
            v[k] = t;
            j++;
        }
    v[r] = v[j];
    v[j] = c;
    return j;
}

void Quicksort(int p, int r, int v[]) {
    int j;
    if (p < r) {
        j = Separa(p, r, v);
        Quicksort(p, j - 1, v);
        Quicksort(j + 1, r, v);
    }
}

int main() {
    int n = 10000, i;
    int *v = malloc(n * sizeof(int));
    for (i = 0; i < n; i++) {
        v[i] = rand();
    }
    clock_t start, end;
    double cpu_time_used;
    start = clock(); 
    Quicksort(0, n - 1, v);
    end = clock();
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC; 
    printf("Tempo de execução: %f milissegundos\n", cpu_time_used * 1000);
    free(v);
    return 0;
}
