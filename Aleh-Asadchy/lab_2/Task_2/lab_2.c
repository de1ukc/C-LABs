#include <stdio.h>
#include <stdlib.h>
#include <math.h>

double fact(int n) {
	if (n == 0)
		return 0;
	if (n == 1)
		return 1;
	return (double)(n * fact(n - 1));
}

int res(int x, double e){
    int n=0;
    double curr=0;
    do {
		n++;
		curr += pow(-1, n - 1) * (pow(x, 2 * n - 1) / fact(2 * n - 1));
       }
	while (fabs(sin(x) - curr) >= e);
    return n;
}

int main()
{
    double epsilon, x;
    printf("Enter x:");
	scanf("%lf", &x);
    printf("Enter epsilon:");
    scanf("%lf", &epsilon);
    printf("n=%d", res(x, epsilon));
    return 0;
}
