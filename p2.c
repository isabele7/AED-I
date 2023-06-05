#include <stdio.h>

#include <stdlib.h>

struct arvore{

    int valor;

    struct arvore *dir;

    struct arvore *esq;

};

typedef struct arvore r;

void inserir(struct arvore r, int numeros){

    int p,f;

    if(r = NULL)

      numeros = r;

    p = f;

    if(p->valor < numeros->valor){

        numeros = p;

    }

    if()

}

void infixa(struct arvore r){

    prefixa(r->esq);

    printf("%d ",r->valor);

    prefixa(r->dir);

}

void prefixa(struct arvore r){

    printf("%d ",r->valor)

    infixa(r->esq);

    infixa(r->dir);

}

void posfixa(struct arvore r){

    posfixa(r->esq);

    posfixa(r->dir);

    printf("%d ",r->valor);

}

int main{

    int n,c,numeros;

    struct arvore r = NULL;

    scanf("%d",&c);

    for(i=0;i<c;i++){

        scanf("%d",&n);

        for(j=0;j<n;j++){

        scanf("%d ",&numeros);

        inserir(r,numeros);

    }

    for(i=1;i<=c;i++){

        printf("Case %d:\n",i);

        printf("Pre.: %d\n",prefixa(r));

        printf("In..: %d\n",infixa(r));

        printf("Post: %d\n",posfixa(r));

        printf("\n");

    }

    return 0;

}
