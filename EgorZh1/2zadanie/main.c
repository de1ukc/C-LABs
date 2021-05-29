#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <locale.h>


int main()
{
  setlocale(0,"");
  FILE *S1, *S2;

  int n,q=1,nx=0,sch=0,w[10000],c,p,g=-1,j=0,hj,f,sum=0,sd,x;
  printf("Введите число : ");
  scanf("%d", &x);

  S1 = fopen("S1.txt", "w");
  fprintf(S1, "%d", x);
  fclose(S1);

  S1 = fopen("S1.txt", "r");
  S2 = fopen("S2.txt", "w");
  fscanf(S1, "%d", &n);

  c=p=n;

    while(q!=0)
    {
        nx = n % 10;
        n = n / 10;
        if(n == 0) q=0;
        sch++;
        nx=n;
    }

    q=1;
    while(q!=0)
    {
        if((sch!=1) ||(p!=1))
        {
            g++;
            j++;
            //Заносим в массив числа
            if((sch-j)!=0)
            {
                hj=pow(10,(sch-j));
                w[g]= p / hj;
                p = p % hj;
            }
            else
            {
                w[g]= p / 1;
                q=0;
            }
            //--------------------------
        }
        else
        {
            g++;
            w[g]=c;
            q=0;
        }
    }
    for(int i=sch-1,gg=0;i>=0;i--,gg++) sum += w[gg]*pow(8,i);

    fclose(S1);
    fprintf(S2, "%d\n", sum);
    fclose(S2);

  return 0;
}
