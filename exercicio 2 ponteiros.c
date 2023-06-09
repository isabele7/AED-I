#include <stdio.h>
#include <stdlib.h>

struct CD {
    char nome[50];
    int dia_lanc, mes_lanc, ano_lanc;
    int dia_contr, mes_contr, ano_contr;
    float valor;
    int num_membros;
    char produtora[50];
};

int main() {
    int n;
    scanf("%d", &n);
    struct CD *bandas = malloc(n * sizeof(struct CD)); 
    for (int i = 0; i < n; i++) {
        scanf("%s", (bandas+i).nome);
        scanf("%d/%d/%d", &(bandas+i).dia_lanc, &(bandas+i).mes_lanc, &(bandas+i).ano_lanc);
        scanf("%d/%d/%d", &(bandas+i).dia_contr, &(bandas+i).mes_contr, &(bandas+i).ano_contr);
        scanf("%f", &(bandas+i).valor);
        scanf("%d", &(bandas+i).num_membros);
        scanf("%s", (bandas+i).produtora);
        printf("\n");
    }

    free(bandas); 

    return 0;
}
  
