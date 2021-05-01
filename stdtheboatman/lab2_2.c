#include <stdio.h>
#include <math.h>

double sinRec(double x, double eps, double a, double b, int znak) {
    double res = a / b * znak;
    if (fabs(res) < eps) {
        return res;
    }
    else {
        return res + sinRec(x, eps, a * x * x, b * (b + 1) * (b + 2), znak * -1);
    }
}

void f(double x, double eps) {
    double sinX = sin(x);

    int znak = 1;

    double a = x;
    double b = 1;

    double sinNow = 0;

    int iteration = 0;
    int mxIteration = 1000000;
    for(;fabs(sinX - sinNow) >= eps && iteration < mxIteration;iteration++) {
        sinNow += a / b * znak;

        a = a * x * x;
        b = b * (b + 1) * (b + 2);

        znak *= -1;
    }

    double sinR = sinRec(x, eps, x, 1, 1);

    printf("Eps %f\n", eps);
    if (iteration != mxIteration) {
        printf("Need %d to reach eps\n", iteration);
    }
    else {
        printf("Need more then %d to reach eps\n", iteration);
    }
    printf("math.h sin(x) = %f\n", sinX);
    printf("mySin(x)      = %f\n", sinNow);
    printf("mySinRec(x)   = %f\n", sinR);
}



int main() {

    double x = 0.6;

    f(x, 1e-4);
    return 0;
}
