#include<bits.h>
const double exp = 0.0001;
double x = 2;

double fact(int n) {
    double res = 1.;
    for(int i = 2; i <= n; i++) res *= (double)i;
    return res;
}
double check(double a, double b) {
    return (a > b) ? a - b : b - a;
}
void rec(double a, double b, int i) {
    if(check(a, b) - exp < 0) {
        printf("%s%lf%c%lf%c", "Rec : ", a, ' ', b, '\n');
        return;
    }
    if(i % 2 == 1) {
        rec(a, b + pow(x, 2 * i - 1) / fact(2 * i - 1), i + 1);
    }  else
    {
        rec(a, b - pow(x, 2 * i - 1) / fact(2 * i - 1), i + 1);
    }
}
int main() {
    double a = sin(x);
    double b = 0;
    int i = 0;
    while(check(a, b) - exp > 0){
        i++;
        if(i % 2 == 1) {
            b += pow(x, 2 * i - 1) / fact(2 * i - 1);
        }  else
        {
            b -= pow(x, 2 * i - 1) / fact(2 * i - 1);
        }
    }
    rec(a, 0, 1);
    printf("%lf%c%lf", a, ' ', b);

}
