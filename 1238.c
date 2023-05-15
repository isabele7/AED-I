#include <stdio.h>
#include <string.h>

#define MAX_LEN 100

int main() {
    int n, i, j;
    char str1[MAX_LEN+1], str2[MAX_LEN+1], result[MAX_LEN*2+1];
    
    scanf("%d", &n);
    while (n--) {
        scanf("%s %s", str1, str2);
        int len1 = strlen(str1), len2 = strlen(str2);
        
        for (i = 0, j = 0; i < len1 && j < len2; i++, j++) {
            result[i*2] = str1[i];
            result[i*2+1] = str2[j];
        }
        
        while (i < len1) {
            result[i+j] = str1[i];
            i++;
        }
        
        while (j < len2) {
            result[i+j] = str2[j];
            j++;
        }
        
        result[i+j] = '\0';
        printf("%s\n", result);
    }
    
    return 0;
}
