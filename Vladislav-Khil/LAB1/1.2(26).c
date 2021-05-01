//Задание 1.2 Вариант 26
#include <stdio.h>

int main()
{
    for (int i = 1; i < 1001; i++)
    {
        int x = i, squareX = i * i;

        while (x && (squareX % 10 == x % 10))
        {
            squareX /= 10;
            x /= 10;
        }

        if (!x)
            printf("[%d] in a square is [%d]\n", i, i * i);
    }
    return 0;
}