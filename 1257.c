#include <stdio.h>
#include <string.h>

int main() {
    int i, j, n, l, k, posicao;
    int valor;
    char string[51];
    scanf("%d", &n);
    
    for (i = 0; i < n; i++) {
        scanf("%d", &l);
        valor = 0;
        
        for (j = 0; j < l; j++) {
            scanf("%s", string);
            
            for (k = 0; string[k] != '\0'; k++) {
                posicao = string[k] - 'A';
                valor += posicao + i + j;
            }
        }
        
        printf("%d\n", valor);
    }
   
    return 0;
}
