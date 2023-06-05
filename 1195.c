#include <stdio.h>
#include <stdlib.h>

typedef struct No {
    int valor;
    struct No* esquerda;
    struct No* direita;
} No;

No* criarNo(int valor) {
    No* novoNo = (No*)malloc(sizeof(No));
    novoNo->valor = valor;
    novoNo->esquerda = NULL;
    novoNo->direita = NULL;
    return novoNo;
}

No* inserir(No* raiz, int valor) {
    if (raiz == NULL) {
        return criarNo(valor);
    } else if (valor < raiz->valor) {
        raiz->esquerda = inserir(raiz->esquerda, valor);
    } else {
        raiz->direita = inserir(raiz->direita, valor);
    }
    return raiz;
}

void percursoPrefixo(No* raiz) {
    if (raiz != NULL) {
        printf(" %d", raiz->valor);
        percursoPrefixo(raiz->esquerda);
        percursoPrefixo(raiz->direita);
    }
}

void percursoInfixo(No* raiz) {
    if (raiz != NULL) {
        percursoInfixo(raiz->esquerda);
        printf(" %d", raiz->valor);
        percursoInfixo(raiz->direita);
    }
}

void percursoPosfixo(No* raiz) {
    if (raiz != NULL) {
        percursoPosfixo(raiz->esquerda);
        percursoPosfixo(raiz->direita);
        printf(" %d", raiz->valor);
    }
}

void liberarArvore(No* raiz) {
    if (raiz != NULL) {
        liberarArvore(raiz->esquerda);
        liberarArvore(raiz->direita);
        free(raiz);
    }
}

int main() {
    int casos;
    scanf("%d", &casos);
    for (int i = 1; i <= casos; i++) {
        int quantidade;
        scanf("%d", &quantidade);
        No* raiz = NULL;
        for (int j = 0; j < quantidade; j++) {
            int valor;
            scanf("%d", &valor);
            raiz = inserir(raiz, valor);
        }
        printf("Case %d:\n", i);
        printf("Pre.:");
        percursoPrefixo(raiz);
        printf("\n");
        printf("In..:");
        percursoInfixo(raiz);
        printf("\n");
        printf("Post:");
        percursoPosfixo(raiz);
        printf("\n\n");
        liberarArvore(raiz);
    }
    return 0;
}
