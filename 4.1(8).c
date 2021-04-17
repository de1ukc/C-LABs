#include <stdio.h>
#include <string.h>
#define LONG_STR 80
#define MAX_WORD 40
int Strlen(char *s) {
    int pos = 0;
    while(s[pos] != '\0') pos++;
    return pos;
}
int check(char *a, char b) {
    for(int j = 0; j < strlen(a); j++) if(a[j] == b) return 1;
    return 0;
}
char *Strcpy(char *str) {
    int size = strlen(str);
    char *result = malloc((size) * sizeof(char));

    for(int i = 0; i < size; i++) {
        result[i] = str[i];
    }
    result[size] = '\0';

    return result;
}
char * Strtok(char * str, const char * delim)
{
    static char * last = 0;
    if (str) {
        last = str;
    }
    if ((last == 0) || (*last == 0)) return 0;
    char * c = last;
    while(check(delim,*c) == 1) ++c;
    if (*c == 0) return 0;
    char * start = c;
    while(*c && (check(delim,*c)==0)) ++c;
    if (*c == 0)
    {
        last = c;
        return start;
    }
    *c = 0;
    last = c+1;
    return start;
}
void main(void)
{
    char *word[MAX_WORD], separator[] = " ,.?!;:", str[LONG_STR];
    int k = 0;
    while(1)
    {
        char* str = malloc(sizeof(char) * LONG_STR);
        if(!gets(str)) break;
        str[LONG_STR - 1] = '\0';
        char *p = strtok(str, separator);
        while (p) {
            word[k] = Strcpy(p);
            k++;
            p = strtok(NULL, separator);
        }
        free(p);
        free(str);
    }
    for (int i = k - 1; i >= 0; i--) {
        int good = 1;
        int n = Strlen(word[i]);
        for(int j = 0; j < n - j - 1; j++) if(word[i][j] != word[i][n - j - 1]) good = 0;
        if(good) puts(word[i]);
        free(word[i]);
    }
    return;
}
/*
ab ab ba cdc ede fffff
a aba de d
*/
