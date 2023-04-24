#include <time.h>
#include <stdio.h>
#include <stdlib.h>

void Insercao (int n, int v[]){
    int i,j,x;
    for(j = 1; j < n; j++){
      x = v[j];
      for( i = j-1; i >= 0 && v[i] > x; i--)
        v[i+1] = v[i];
      v[i+1] = x;
    }
}

int main(){
  
  int i, n = 20000;
  int v[n];
  for (i = 0; i < n; i++) {
        v[i] = rand();
  }
  
  clock_t start, end;
  double tempo_gasto; 

  start = clock();
  Insercao(n, v);
  end = clock();

  tempo_gasto = ((double) (end - start)) / CLOCKS_PER_SEC;
  printf("Tempo de execução: %f ms \n", tempo_gasto * 1000);
  return 0;
}
