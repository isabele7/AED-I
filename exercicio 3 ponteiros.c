#include <stdio.h>
#include <stdlib.h>

struct aluno{
  char nome [81];
  int mat;
  char end[121];
  char tel[21];
};
typedef struct aluno Aluno;


void inicializa_tabela(Aluno* tabela, int n) {
    int i;
    for (i = 0; i < n; i++) {
        tabela[i].mat = -1;
    }
}


void armazena_aluno(Aluno* tabela, int posicao) {
    Aluno novo_aluno;
    printf("Nome: ");
    scanf("%s", novo_aluno.nome);
    printf("Matricula: ");
    scanf("%d", &novo_aluno.mat);
    printf("Endereco: ");
    scanf("%s", novo_aluno.end);
    printf("Telefone: ");
    scanf("%s", novo_aluno.tel);
    tabela[posicao] = novo_aluno;
}

void mostra_aluno(Aluno* tabela, int posicao) {
    if (tabela[posicao].mat == -1) {
        printf("Nao ha dados para essa posicao.\n");
    } else {
        printf("Nome: %s\n", tabela[posicao].nome);
        printf("Matricula: %d\n", tabela[posicao].mat);
        printf("Endereco: %s\n", tabela[posicao].end);
        printf("Telefone: %s\n", tabela[posicao].tel);
    }
}

int main() {
    int n;
    scanf("%d", &n);
    Aluno* tabela = malloc(n * sizeof(Aluno));
    inicializa_tabela(tabela, n);
    if (tabela == NULL) {
        printf("Erro ao alocar a memoria!\n");
        return 1;
    }
    int opcao = 0;
    int posicao;
    while (opcao != 4) {
        printf("Escolha uma opcao:\n");
        printf("1 - Armazenar aluno\n");
        printf("2 - Mostrar aluno\n");
        printf("3 - Mostrar todos os alunos\n");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                printf("Digite a posicao (1 a %d): ", n);
                scanf("%d", &posicao);
                if (posicao >= 1 && posicao < n) {
                    armazena_aluno(tabela, posicao-1);
                } else {
                    printf("Posicao invalida.\n");
                }
                break;

            case 2:
                printf("Digite a posicao (1 a %d): ", n);
                scanf("%d", &posicao);
                if (posicao >= 0 && posicao < n) {
                    mostra_aluno(tabela, posicao-1);
                } else {
                    printf("Posicao invalida.\n");
                   }
                break;

            case 3:
                for (int i = 0; i < n; i++) {
                    mostra_aluno(tabela, i);
                }
                break;

            default:
                printf("Opcao invalida.\n");
        }
    }
  
    free(tabela);
    return 0;
}
