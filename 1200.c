#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct arvore {
    int chave;
    char conteudo;
    struct arvore *esq;
    struct arvore *dir;
};

typedef struct arvore no;

void imprime_erd(struct arvore *r) {
    if (r != NULL) {
        imprime_erd(r->esq);
        printf("%c ", r->conteudo);
        imprime_erd(r->dir);
    }
}

void imprime_red(struct arvore *r) {
    if (r != NULL) {
        printf("%c ", r->conteudo);
        imprime_red(r->esq);
        imprime_red(r->dir);
    }
}

void imprime_edr(struct arvore *r) {
    if (r != NULL) {
        imprime_edr(r->esq);
        imprime_edr(r->dir);
        printf("%c ", r->conteudo);
    }
}

struct arvore* Busca(struct arvore *r, int k) {
    if (r == NULL || r->chave == k)
        return r;
    if (r->chave > k)
        return Busca(r->esq, k);
    else
        return Busca(r->dir, k);
}

struct arvore* Insere(struct arvore *r, no *novo) {
    if (r == NULL)
        return novo;
    if (r->chave > novo->chave)
        r->esq = Insere(r->esq, novo);
    else
        r->dir = Insere(r->dir, novo);
    return r;
}

int main() {
    char operacao[10];
    int n;
    struct arvore *r = NULL;

    while (scanf("%s", operacao) != EOF) {
        if (strcmp(operacao, "I") == 0) {
            scanf("%d", &n);
            struct arvore *novo = (struct arvore*)malloc(sizeof(struct arvore));
            novo->chave = n;
            scanf(" %c", &(novo->conteudo));
            novo->esq = NULL;
            novo->dir = NULL;
            r = Insere(r, novo);
        } else if (strcmp(operacao, "INFIXA") == 0) {
            imprime_erd(r);
            printf("\n");
        } else if (strcmp(operacao, "PREFIXA") == 0) {
            imprime_red(r);
            printf("\n");
        } else if (strcmp(operacao, "POSFIXA") == 0) {
            imprime_edr(r);
            printf("\n");
        } else if (strcmp(operacao, "P") == 0) {
            scanf("%d", &n);
            struct arvore *resultado = Busca(r, n);
            if (resultado == NULL)
                printf("%d nao existe\n", n);
            else
                printf("%d existe\n", n);
        }
    }

    return 0;
}
