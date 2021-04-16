#include <stdio.h>
#include <string.h>
#define LONG_STR 80 /* длина вводимой строки */
#define MAX_WORD 40 /* максимальное количество слов в строке */
//ctrl+z == остановить ввод
int my_strlen(char * c)
{ int counter = 0 ;
int i = 0;
    while (c[i] != '\0')
    {
     counter++;
     i++;
    }
return counter;
}

char * my_strcpy(char *destination, char * source)
{
char *ans = destination;
while (*source != '\0')
{
    *destination = *source;
    destination++;
    source++;
}
*destination = '\0';
return ans;

}

int check(char *a, char b) {
    for(int j = 0; j < my_strlen(a); j++) if(a[j] == b) return 1;
    return 0;
}
char * my_strtok(char * str, const char * delim)
{
    static char * last = 0;
    if (str) last = str;
    if ((last == 0) || (*last == 0)) return 0;
    char * c = last;
    while(check(delim, *c)) c++;
    if (*c == 0) return 0;
    char * start = c;
    while(*c && (check(delim, c)==0)) ++c;
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
        char *str = malloc(sizeof(char) * LONG_STR);
        if(!gets(str)) {free(str); break;}

        str[LONG_STR - 1] = '\0';
        char *p = my_strtok(str, separator);
        while (p) {
            word[k++] = (char*)malloc (my_strlen(p));
            my_strcpy(word[k-1],p);
            p = my_strtok(NULL, separator);
        }
        free(str);
    }
    for(int i = 0; i < k; i++) {
        for(int j = i + 1; j < k; j++) if(my_strlen(word[i]) > my_strlen(word[j]) ){
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
