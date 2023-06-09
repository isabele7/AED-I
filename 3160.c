#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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

//A função recebe um ponteiro para uma lista de amigos e um nome e insere um novo amigo com esse nome no final da lista. Se a lista estiver vazia, o novo amigo é o primeiro da lista
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

//A função recebe um ponteiro para uma lista de amigos e uma string com nomes de amigos separados por espaço. Ela chama a função inserir_amigo para cada nome na string, adicionando-os um a um à lista
void inserir_lista_amigos(Amigo** lista, char lista_nova[]) {
    char* token = strtok(lista_nova, " ");
    while (token != NULL) {
        inserir_amigo(lista, token);
        token = strtok(NULL, " ");
    }
}

//A função recebe um ponteiro para uma lista de amigos e imprime os nomes de todos os amigos nessa lista
void imprimir_lista_amigos(Amigo* lista) {
    int primeiro = 1;
    while (lista != NULL) {
        if (!primeiro) {
            printf(" ");
        }
        printf("%s", lista->nome);
        lista = lista->prox;
        primeiro = 0;
    }
    printf("\n");
}

 //A função recebe um ponteiro para uma lista de amigos, uma string com nomes de amigos separados por espaço e o nome de um amigo que indicou a lista
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

//No programa principal são declaradas três strings para entrada de dados: a lista inicial de amigos, a lista nova e o amigo que recebe a indicação
int main() {
    char amigos[100];
    char lista_nova[100];
    char amigo_indicacao[20];
    Amigo* lista = NULL;
    fgets(amigos, 100, stdin);
    amigos[strcspn(amigos, "\n")] = '\0'; 
    inserir_lista_amigos(&lista, amigos);
    fgets(lista_nova, 100, stdin);
    lista_nova[strcspn(lista_nova, "\n")] = '\0'; 
    fgets(amigo_indicacao, 20, stdin);
    amigo_indicacao[strcspn(amigo_indicacao, "\n")] = '\0';
    inserir_amigos_indicacao(&lista, lista_nova, amigo_indicacao);
    imprimir_lista_amigos(lista);
    return 0;
}
