
#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>

int main()
{
    system("chcp 1251");
    system("cls");
    int countY = 0, countD = 0;
    double p, k, t , m;
    int check = 0;

    printf("Введите объем древисины в лесу:\n");
    scanf_s("%lf", &p);

    printf("Введите ежегодный прирост заготовок в процентах:\n");
    scanf_s("%lf", &k);

    printf("Введите годовой план заготовки:\n");
    scanf("%lf", &t);


    m = p;
    while (!check)
    {
        if (p - t > 0)
        {
            p = p + p * k / 100 - t;
            countY++;
        }
        if (p > m)
        {
            check = 1;
            printf("\nТакими темпами деревья никогда не исчезнут :)");
        }
        if(p - t < 0 )
            check = 1;
    }

    if (p < m)
    {
        countD = p / (t / 365);
        printf("Деревья исчезнут через: %d г. и %d д.\n", countY, countD);
    }

}
