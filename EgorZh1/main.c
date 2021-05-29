#include <stdio.h>
#include <math.h>
#include <conio.h>

int main()
{
    int k, v=1, i=100, a[100000], b, bx, c, by, q=1,sch=0, g=-1, p, j=0,m,l=1,hj;
    printf("100101102103104...\n");
    printf("Enter K: ");
    scanf("%d", &k);
    if(k==0)
    {
        printf("0");
        return 0;
    }

    while(l!=0)
    {
        p=b=c=i;
        //Находим количество цифр в числе
        while(q!=0)
        {
            bx = b % 10;
            b = b / 10;
            if(b == 0) q=0;
            sch++;
            bx=b;
        }
        j=0;
        q=1;
        //----------------------------------

        while(q!=0)
        {

            if(sch!=1)
            {
                  g++;
                  j++;
                  //Заносим в массив числа
                  if((sch-j)!=0)
                  {
                      hj=pow(10,(sch-j));
                      a[g]= p / hj;
                      p = p % hj;
                  }
                  else
                  {
                       a[g]= p / 1;
                       q=0;
                  }
                  //--------------------------
            }
            else
               {
                   g++;
                   a[g]=c;
                   q=0;
               }
            if((g+1)==k)
            {
                l=0;
            }
        }
        sch=0;
        q=1;
        i++;
        if((g+1)==k) l=0;
    }

  //  printf("%d",a[k-1]);

    return 0;
}
