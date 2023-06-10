#include <stdio.h>
#include <stdlib.h>

typedef struct No {
    int chave;
    struct No* prox;
} No;

No** criarTabelaHash(int tamanho) {
    No** tabelaHash = (No**)malloc(tamanho * sizeof(No*));
    for (int i = 0; i < tamanho; i++) {
        tabelaHash[i] = NULL;
    }
    return tabelaHash;
}

void inserirChave(No** tabelaHash, int tamanho, int chave) {
    int indice = chave % tamanho;

    No* novoNo = (No*)malloc(sizeof(No));
    novoNo->chave = chave;
    novoNo->prox = NULL;

    if (tabelaHash[indice] == NULL) {
        tabelaHash[indice] = novoNo;
    } else {
        No* atual = tabelaHash[indice];
        while (atual->prox != NULL) {
            atual = atual->prox;
        }
        atual->prox = novoNo;
    }
}

void imprimirTabelaHash(No** tabelaHash, int tamanho) {
    for (int i = 0; i < tamanho; i++) {
        printf("%d -> ", i);
        No* atual = tabelaHash[i];
        if (atual == NULL) {
            printf("\\\n");
        } else {
            while (atual != NULL) {
                printf("%d -> ", atual->chave);
                atual = atual->prox;
            }
            printf("\\\n");
        }
    }
}

void liberarTabelaHash(No** tabelaHash, int tamanho) {
    for (int i = 0; i < tamanho; i++) {
        No* atual = tabelaHash[i];
        while (atual != NULL) {
            No* temp = atual;
            atual = atual->prox;
            free(temp);
        }
    }
    free(tabelaHash);
}

int main() {
    int numCasos;
    scanf("%d", &numCasos);

    for (int i = 0; i < numCasos; i++) {
        int tamanho, numChaves;
        scanf("%d %d", &tamanho, &numChaves);

        No** tabelaHash = criarTabelaHash(tamanho);

        for (int j = 0; j < numChaves; j++) {
            int chave;
            scanf("%d", &chave);
            inserirChave(tabelaHash, tamanho, chave);
        }

        imprimirTabelaHash(tabelaHash, tamanho);

        liberarTabelaHash(tabelaHash, tamanho);

        if (i < numCasos - 1) {
            printf("\n");
        }
    }

    return 0;
}
