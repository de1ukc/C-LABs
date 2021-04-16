#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define N 128 /* количество символов в строке */
int check(char *a, char *b) {
    if(strlen(a) != strlen(b)) {
        return 0;
    }
    int n = strlen(a);
    for(int i = 0; i < n - i - 2; i++) if(a[i] != b[n - i - 2]) return 0;
    return 1;
}
void main(void)
{
    FILE *fp;
    fp = fopen("000.txt", "r");
    if (!fp) exit(1); /* если файл не найден – выход */
    char *word[80];
    int k =0;
    while (1){

        char *buffer = malloc(sizeof(char) * N);
        if(fgets(buffer, N, fp) == NULL) break;
        word[k++] = buffer;
    }
    for(int i = 0; i < k; i++)
        for(int j = i + 1; j < k; j++)
        {
            if(check(word[i], word[j]))
        {
            puts(word[i]);
            puts(word[j]);
            printf("%c", '\n');
            free(word[j]);
        }
            free(word[i]);
        }
    fclose(fp);
}
