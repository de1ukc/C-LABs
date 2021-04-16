#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define N 128 /* количество символов в строке */
int check(char *a, char *b) {
    if(my_strlen(a) != my_strlen(b)) {
        return 0;
    }
    int n = my_strlen(a);
    for(int i = 0; i < n - i - 2; i++) if(a[i] != b[n - i - 2]) return 0;
    return 1;
}

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
        //word[k++] = buffer;
        word[k++] = (char*)malloc(my_strlen(buffer));
        my_strcpy(word[k-1],buffer);
        free(buffer);
    }
    for(int i = 0; i < k; i++)
        for(int j = i + 1; j < k; j++)
        {
            if(check(word[i], word[j]))
        {
            puts(word[i]);
            puts(word[j]);
            printf("%c", '\n');
        }
            free(word[i]);
        }
        free(word);
    fclose(fp);
}
