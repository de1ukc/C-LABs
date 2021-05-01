#include <stdio.h>
#include <math.h>
#include <stdbool.h>

double Fact(int k)
{
    if (k < 0)
    {
        return 0;
    }
    if (k == 0)
    {
        return 1;
    }
    else
    {
        return k * Fact(k - 1);
    }
}

int Recursion(double x, double e, int k, double sum)
{
    if (fabs(sin(x) - sum) < e)
    {
        printf("\nRecursion:\n\nsin(x) = %lf.\nExpression = %lf.\n", sin(x), sum);
        return k;
    }

    k++;
    sum += pow(-1, k - 1) * pow(x, 2 * k - 1) / Fact(2 * k - 1);
    return Recursion(x, e, k, sum);
}

int Iteration(double x, double e, int k, double sum)
{
    while ((fabs(sin(x) - sum) > e))
    {
        k++;
        sum += pow(-1, k - 1) * pow(x, 2 * k - 1) / Fact(2 * k - 1);
    }

    printf("\nIteration:\n\nsin(x) = %lf.\nExpression = %lf.\n", sin(x), sum);
    return k;
}

int main() {
    double x = 0;
    double e = 0;
    char exit;

    while (true)
    {
        printf("Enter x: ");
        scanf_s("%lf.", &x);
        fflush(stdin);

        printf("Enter e: ");
        scanf_s("%lf", &e);
        fflush(stdin);

        printf("Yours choise: x = %lf, e = %lf.\n", x, e);

        printf("k = %d.\n", Recursion(x, e, 1, x));
        printf("k = %d.\n\n", Iteration(x, e, 1, x));

        printf("If you want continue - enter 'y' into console.\nYour Choise: ");
        while ((getchar()) != '\n');
        exit = getchar();
        if (exit == 'y')
        {
            continue;
        }
        else
        {
            return 0;
        }

    }
    return 0;
}