#include <stdio.h>
#include <string.h>
 
int main() {
 
    int N,K,i,j,min;
    char alunos[100][21],aluno_bonus[21],aux[21];
    scanf("%d %d",&N,&K);
    //leitura dos nomes
    for (i = 0; i < N; i++) {
        scanf("%s", alunos[i]);
    }
    //organização dos nomes por ordem alfabética usando algoritmo de seleção
    for(i = 0; i < N; i++){
     min = i;
     for(j = i+1; j < N; j++)
       if(strcmp(alunos[j], alunos[min]) < 0)
        min = j;
    strcpy(aux,alunos[i]);
    strcpy(alunos[i],alunos[min]);
    strcpy(alunos[min],aux);
    }
    //identificação e impressão do aluno premiado
    strcpy(aluno_bonus, alunos[K-1]);
    printf("%s\n",aluno_bonus);
    return 0;
    
}
