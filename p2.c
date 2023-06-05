#include <stdio.h>
#include <stdlib.h>

struct arvore {
    int valor;
    struct arvore *esq;
    struct arvore *dir;
};

typedef struct arvore No;

No* criarNo(int valor) {
    No* novoNo = (No*)malloc(sizeof(No));
    novoNo->valor = valor;
    novoNo->esq = NULL;
    novoNo->dir = NULL;
    return novoNo;
}

No* inserir(No* r, int numeros) {
    if (r == NULL) {
        return criarNo(numeros);
    } else if (numeros < r->valor) {
        r->esq = inserir(r->esq, numeros);
    } else {
        r->dir = inserir(r->dir, numeros);
    }
    return r;
}

void prefixa(No* r) {
    if (r != NULL) {
        printf("%d ", r->valor);
        prefixa(r->esq);
        prefixa(r->dir);
    }
}

void infixa(No* r) {
    if (r != NULL) {
        infixa(r->esq);
        printf("%d ", r->valor);
        infixa(r->dir);
    }
}

void posfixa(No* r) {
    if (r != NULL) {
        posfixa(r->esq);
        posfixa(r->dir);
        printf("%d ", r->valor);
    }
}

void liberarArvore(No* r) {
    if (r != NULL) {
        liberarArvore(r->esq);
        liberarArvore(r->dir);
        free(r);
    }
}

int main() {
    int casos;
    scanf("%d", &casos);
    for (int i = 1; i <= casos; i++) {
        int quantidade;
        scanf("%d", &quantidade);
        No* r = NULL;
        for (int j = 0; j < quantidade; j++) {
            int numeros;
            scanf("%d", &numeros);
            r = inserir(r, numeros);
        }
        printf("Case %d:\n", i);
        printf("Pre.: ");
        prefixa(r);
        printf("\n");
        printf("In..: ");
        infixa(r);
        printf("\n");
        printf("Post: ");
        posfixa(r);
        printf("\n\n");
        liberarArvore(r);
    }
    return 0;
}
