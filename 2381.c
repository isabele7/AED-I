#include <stdio.h>
#include <string.h>

int main(){
  int N,K,i,j;
  char nomes[100][21],aluno_bonus[21],aux[21];
  scanf("%d %d", &N, &K);
  //leitura dos nomes
  for (i = 0; i < N; i++) {
    scanf("%s", nomes[i]);
  }
  //organização dos nomes por ordem alfabética usando algoritmo de seleção
  for (int i = 0; i < N-1; i++) {
    int min = i;
    for (int j = i+1; j < N; j++) {
      if (strcmp(nomes[j], nomes[min]) < 0) {
        min = j;
      }
    }
    strcpy(aux, nomes[i]);
    strcpy(nomes[i], nomes[min]);
    strcpy(nomes[min], aux);
  }
  //identificação e impressão do aluno premiado
  strcpy(aluno_bonus, nomes[K-1]);
  printf("%s",aluno_bonus);
  return 0;
}
