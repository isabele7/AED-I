#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_LENGTH 100001

// Recebe a palavra 'a' e o texto 'b'. Caso essa palavra esteja no texto, ela retorna 1; caso contrário, retorna 0.
int busca_string(char a[], char b[]) {
    int m = strlen(a), n = strlen(b), i, j;
    for (i = 0; i <= n - m; i++) {
        for (j = 0; j < m; j++) {
            //a função tolower converte todos os caracteres de entrada de 'b' em minúsculas
            if (tolower(a[j]) != tolower(b[i + j]))
                break;
        }
        if (j == m)
            return 1; //a está em b, a partir da posição i
    }
    return 0; //a não está em b
}

int main() {
    char a[] = "zelda";
    char b[MAX_LENGTH];
    int ocorrs;
    fgets(b, sizeof(b), stdin);
    b[strcspn(b, "\n")] = '\0'; 
    ocorrs = busca_string(a, b);
    if (ocorrs)
        printf("Link Bolado\n");
    else
        printf("Link Tranquilo\n");
    return 0;
}
