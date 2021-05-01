#include <stdio.h>

int check10(int num)
{
    int divider = 10, ten, unit, hundred, sum1, sum2, divNum, bigNum;
    ten = num / divider;
    unit = num % divider;
    sum1 = ten + unit;
    for (int i = 2; i < 10; i++)
    {
        bigNum = num * i;
        if (bigNum > 100)
        {
            hundred = bigNum / 100;
            divNum = bigNum % 100;
            ten = divNum / divider;
            unit = divNum % divider;
            sum2 = ten + unit + hundred;
        }
        else if (bigNum % 100 == 0)
        {
            sum2 = bigNum / 100;
        }
        else
        {
            ten = bigNum / divider;
            unit = bigNum % divider;
            sum2 = ten + unit;
        }
        if (sum1 == sum2) {}
        else
            return 0;
    }
    return 1;
}

int main()
{
    printf("Resul: ");
    for (int dividend = 10, truthMaker; dividend < 100; dividend++)
    {
        truthMaker = check10(dividend);
        if (truthMaker == 1)
        {
            printf("%d", dividend);
            printf("\t");
        }
    }
    return 0;
}