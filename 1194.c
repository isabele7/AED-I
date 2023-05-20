#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_N 52

typedef struct no {
    char valor;
    struct no* esquerda;
    struct no* direita;
} No;

No* construirArvore(char* infixa, char* prefixa, int n);
void imprimirInfixa(No* raiz);

int main() {
    int c;
    scanf("%d", &c);
    while (c--) {
        int n;
        scanf("%d", &n);
        char prefixa[MAX_N + 1], infixa[MAX_N + 1];
        scanf("%s %s", prefixa, infixa);
        No* raiz = construirArvore(infixa, prefixa, n);
        imprimirInfixa(raiz);
        printf("\n");
    }
    return 0;
}

No* construirArvore(char* infixa, char* prefixa, int n) {
    if (n == 0)
        return NULL;

    char valorRaiz = prefixa[0];
    int indiceRaiz = strchr(infixa, valorRaiz) - infixa;

    No* raiz = (No*)malloc(sizeof(No));
    raiz->valor = valorRaiz;
    raiz->esquerda = construirArvore(infixa, prefixa + 1, indiceRaiz);
    raiz->direita = construirArvore(infixa + indiceRaiz + 1, prefixa + indiceRaiz + 1, n - indiceRaiz - 1);

    return raiz;
}

void imprimirInfixa(No* raiz) {
    if (raiz == NULL)
        return;

    imprimirInfixa(raiz->esquerda);
    printf("%c", raiz->valor);
    imprimirInfixa(raiz->direita);
}
