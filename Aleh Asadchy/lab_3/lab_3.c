#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
int main()
{
    int N;
    printf("%s","Enter size of array : ");
    scanf("%d", &N);
    int i = 0,j = 0;
    int **a;     // source array
    int **flags; // map
    int *b;      // output array
    a = (int**)malloc (sizeof(int*)*N);
    flags = (int**)malloc (sizeof(int*)*N);
    b = (int*)malloc(sizeof(int*)*(N*N));
    
    for (int i = 0 ; i < N ; ++i)
    {
        a[i] =(int*)malloc(sizeof(int*)*(N));
    }
    
    for (int i = 0 ; i < N; ++i)
    {
        flags[i] =(int*)malloc(sizeof(int*)*(N));
    }
    
for(int i = 0; i < N; i++)
for(int j = 0; j < N; j++)
    flags[i][j] = 0;
        
for (int i = 0; i < N; i++)
for (int j = 0; j < N; j++)
    a[i][j] = i*N + j;

int pos = 0;
    
while(flags[i][j] == 0)
{
    while (j < N && flags[i][j] == 0)
        {
            b[pos++] = a[i][j];
            flags[i][j] = 1;
            j++;
        }
    
    j--;
    i++;

    while (i < N && flags[i][j] == 0)
    {
       b[pos++] = a[i][j];
       flags[i][j] = 1;
       i++;
    }

    i--;
    j--;

    while (j >= 0 && flags[i][j] == 0)
             {
                b[pos++] = a[i][j];
                flags[i][j] = 1;
                j--;
             }
    j++;
    i--;
    
    while (i >= 0 && flags[i][j] == 0)
             {
                b[pos++] = a[i][j];
                flags[i][j] = 1;
                i--;
             }
    i++;
    j++;
}

for (int i = (N*N) - 1; i >= 0; i--)
    printf("%d%c",b[i],' ');

        for(int i = 0 ; i < N; ++i)
        {
            free(a[i]);
        }
           free(a);
    
        for(int i = 0 ; i < N; ++i)
        {
            free(flags[i]);
        }
           free(flags);
            free(b);
           

    return 0;
}
