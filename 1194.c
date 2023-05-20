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

// Função para construir a árvore binária com base nos percursos infixa e prefixa.  Ela recebe o percurso infixa, o percurso prefixa e o tamanho n da árvore como argumentos. Ela constrói a árvore binária recursivamente dividindo a tarefa em subárvores esquerda e direita com base na posição da raiz no percurso infixa.
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

// Função para imprimir o percurso infixa da árvore. Ela chama recursivamente imprimirInfixa para a subárvore esquerda da raiz, imprimindo os valores dos nós da subárvore esquerda em ordem infixa. Depois, imprime o valor da raiz.. Por fi, chama recursivamente imprimirInfixa para a subárvore direita da raiz, imprimindo os valores dos nós da subárvore direita em ordem infixa.
void imprimirInfixa(No* raiz) {
    if (raiz == NULL)
        return;

    imprimirInfixa(raiz->esquerda);
    printf("%c", raiz->valor);
    imprimirInfixa(raiz->direita);
}
