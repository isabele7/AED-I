#include <stdio.h>

int main() {
    int x, y, i, j;
    char mapa[100][100];
    scanf("%d%d", &x, &y);

    for (i = 0; i < y; i++) {
        for (j = 0; j < x; j++) {
            scanf(" %c", &mapa[i][j]);
        }
    }

    int posX = 0, posY = 0, dirX = 1, dirY = 0;
    int visitados[100][100] = {0};  // Matriz para marcar as posições visitadas

    while (posX >= 0 && posX < x && posY >= 0 && posY < y) {
        if (visitados[posY][posX]) {
            printf("!\n");
            return 0;
        }
        
        visitados[posY][posX] = 1;  // Marca a posição como visitada
        
        char c = mapa[posY][posX];
        if (c == '.') {
            posX += dirX;
            posY += dirY;
        } else if (c == '>' || c == '<' || c == 'v' || c == '^') {
            if (c == '>') {
                dirX = 1; dirY = 0;
            } else if (c == '<') {
                dirX = -1; dirY = 0;
            } else if (c == 'v') {
                dirX = 0; dirY = 1;
            } else if (c == '^') {
                dirX = 0; dirY = -1;
            }
            posX += dirX;
            posY += dirY;
        } else if (c == '*') {
            printf("*\n");
            return 0;
        } else {
            printf("!\n");
            return 0;
        }
    }

    printf("!\n");
    return 0;
}
