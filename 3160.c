#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//A struct amigo possui um campo para nome e um ponteiro para o próximo da lista

typedef struct amigo {
    char nome[20];
    struct amigo *prox;
} Amigo;

Amigo* criar_amigo(char nome[]) {
    Amigo* novo = (Amigo*) malloc(sizeof(Amigo));
    strcpy(novo->nome, nome);
    novo->prox = NULL;
    return novo;
}

void inserir_amigo(Amigo** lista, char nome[]) {
    Amigo* novo = criar_amigo(nome);
    if (*lista == NULL) {
        *lista = novo;
    } else {
        Amigo* aux = *lista;
        while (aux->prox != NULL) {
            aux = aux->prox;
        }
        aux->prox = novo;
    }
}

void inserir_lista_amigos(Amigo** lista, char lista_nova[]) {
    char* token = strtok(lista_nova, " ");
    while (token != NULL) {
        inserir_amigo(lista, token);
        token = strtok(NULL, " ");
    }
}

void imprimir_lista_amigos(Amigo* lista) {
    while (lista != NULL) {
        printf("%s ", lista->nome);
        lista = lista->prox;
    }
    printf("\n");
}

void inserir_amigos_indicacao(Amigo** lista, char lista_nova[], char amigo_indicacao[]) {
    if (strcmp(amigo_indicacao, "nao") == 0) {
        inserir_lista_amigos(lista, lista_nova);
    } else {
        Amigo* novo_inicio = NULL;
        inserir_lista_amigos(&novo_inicio, lista_nova);
        Amigo* aux = *lista;
        Amigo* ant = NULL;
        while (aux != NULL && strcmp(aux->nome, amigo_indicacao) != 0) {
            ant = aux;
            aux = aux->prox;
        }
        if (ant == NULL) {
            *lista = novo_inicio;
        } else {
            ant->prox = novo_inicio;
        }
        while (novo_inicio->prox != NULL) {
            novo_inicio = novo_inicio->prox;
        }
        novo_inicio->prox = aux;
    }
}

int main() {
    char amigos[100];
    char lista_nova[100];
    char amigo_indicacao[20];
    Amigo* lista = NULL;

    fgets(amigos, 100, stdin);
    amigos[strcspn(amigos, "\n")] = '\0'; // remove o caractere de nova linha
    inserir_lista_amigos(&lista, amigos);

    fgets(lista_nova, 100, stdin);
    lista_nova[strcspn(lista_nova, "\n")] = '\0'; // remove o caractere de nova linha

    fgets(amigo_indicacao, 20, stdin);
    amigo_indicacao[strcspn(amigo_indicacao, "\n")] = '\0'; // remove o caractere de nova linha

    inserir_amigos_indicacao(&lista, lista_nova, amigo_indicacao);
    imprimir_lista_amigos(lista);

    return 0;
}
