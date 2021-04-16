#include <stdio.h>
#include <string.h>
#define LONG_STR 80 /* длина вводимой строки */
#define MAX_WORD 40 /* максимальное количество слов в строке */
//ctrl+z == остановить ввод
void main(void)
{
    char *word[MAX_WORD], separator[] = " ,.?!;:", str[LONG_STR];
    int k = 0;
    while(1)
    {
        char *str = malloc(sizeof(char) * LONG_STR);
        if(!gets(str)) {free(str); break;}

        str[LONG_STR - 1] = '\0';
        char *p = strtok(str, separator);
        while (p) {
            word[k++] = (char*)malloc (strlen(p));
            strcpy(word[k-1],p);
            p = strtok(NULL, separator);
        }
        free(str);
    }
    for(int i = 0; i < k; i++) {
        for(int j = i + 1; j < k; j++) if(strlen(word[i]) > strlen(word[j]) ){
            char *tmp;
            tmp = word[j];
            word[j] = word[i];
            word[i] = tmp;
        }
    }
   // printf("%d%c", k, '\n');
    for (int i = 0; i < k; i++) {
        puts(word[i]);
        free(word[i]);
    }

}
