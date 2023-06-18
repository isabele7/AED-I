#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

#define MAX_WORDS 5000
#define MAX_LENGTH 201

typedef struct {
    char palavras[MAX_LENGTH];
} string;

bool stringSrc(const char *str, string *dicionario, unsigned tam);
void qSortAlphaParcial(string *dicionario, int inicio, int fim);
void imprimirPalavras(string *dicionario, int tam);

int main() {
    unsigned k = 0;
    char tempEntrada[MAX_LENGTH];
    string dicionario[MAX_WORDS];
    while (scanf(" %[^\n]", tempEntrada) != EOF) {
        int i = 0;
        int j = 0;
        int len = strlen(tempEntrada);
        while (i <= len) {
            char tempSaida[MAX_LENGTH];
            int tempIndex = 0;
            while (i < len && isalpha(tempEntrada[i])) {
                tempSaida[tempIndex++] = tolower(tempEntrada[i++]);
            }
            tempSaida[tempIndex] = '\0';
            if (!stringSrc(tempSaida, dicionario, k)) {
                strcpy(dicionario[k].palavras, tempSaida);
                k++;
            }
            i++;
            memset(tempSaida, 0, sizeof(tempSaida));
        }
        memset(tempEntrada, 0, sizeof(tempEntrada));
    }
    qSortAlphaParcial(dicionario, 0, k - 1);
    imprimirPalavras(dicionario, k);
    return 0;

}

bool stringSrc(const char *str, string *dicionario, unsigned tam) {
    for (unsigned i = 0; i < tam; i++) {
        if (strcmp(dicionario[i].palavras, str) == 0) {
            return true;
        }
    }
    return false;
}

void qSortAlphaParcial(string *dicionario, int inicio, int fim) {
    if (inicio < fim) {
        int i = inicio;
        int j = fim;
        string pivo = dicionario[(i + j) / 2];
        do {
            while (strcmp(dicionario[i].palavras, pivo.palavras) < 0) {
                i++;
            }
            while (strcmp(dicionario[j].palavras, pivo.palavras) > 0) {
                j--;
            }
            if (i <= j) {
                string temp = dicionario[i];
                dicionario[i] = dicionario[j];
                dicionario[j] = temp;
                i++;
                j--;
            }
        } while (i <= j);
        qSortAlphaParcial(dicionario, inicio, j);
        qSortAlphaParcial(dicionario, i, fim);
    }
}

void imprimirPalavras(string *dicionario, int tam) {
    for (int i = 0; i < tam; i++) {
        printf("%s\n", dicionario[i].palavras);
    }
}
