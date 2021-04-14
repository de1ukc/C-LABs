#include <stdio.h>
#include <string.h>
#define LONG_STR 80 /* äëèíà ââîäèìîé ñòðîêè */
#define MAX_WORD 40 /* ìàêñèìàëüíîå êîëè÷åñòâî ñëîâ â ñòðîêå */
//ctrl+z == îñòàíîâèòü ââîä
void main(void)
{
    char *word[MAX_WORD], separator[] = " ,.?!;:", str[LONG_STR];
    int k = 0;
    while(1)
    {
        char *str = malloc(sizeof(char) * LONG_STR);
        if(!gets(str)) break;

        str[LONG_STR - 1] = '\0';
        char *p = strtok(str, separator);
        while (p) {
            word[k++] = p;
            p = strtok(NULL, separator);
        }
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
    for (int i = 0; i < k; i++) 
    {
        puts(word[i]);
    }

}
