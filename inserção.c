#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void Insercao(int n, int v[]){
    int i, j, x;
    for(j = 1; j < n; j++){
        x = v[j];
        for( i = j-1; i >= 0 && v[i] > x; i--)
            v[i+1] = v[i];
        v[i+1] = x;
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
    Insercao(n, v);
    end = clock();
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC; 
    printf("Tempo de execução: %f milissegundos\n", cpu_time_used * 1000);
    return 0;
}
