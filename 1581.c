#include <stdio.h>

#define MAX_LANG_LEN 20

int main() {
    int N;
    scanf("%d", &N);
    while (N > 0) {
        int K;
        scanf("%d", &K);
        char languages[K][MAX_LANG_LEN + 1];
        int i;
        for (i = 0; i < K; i++) {
            scanf("%s", languages[i]);
        }
        int j;
        for (j = 1; j < K; j++) {
            if (strcmp(languages[j], languages[j - 1]) != 0) {
                printf("ingles\n");
                break;
            }
        }
        if (j == K) {
            printf("%s\n", languages[0]);
        }
        N--;
    }
    return 0;
}
