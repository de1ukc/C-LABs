//Task 2.2, Variant 6.
#include <stdio.h>
#include <math.h>
#include <stdbool.h>
#include <time.h>

double performFactorial(int n) {
    if (n < 0) return 0;
    
    if (n == 0) return 1;
    
    else return n * performFactorial(n - 1);
}

int сalculateRecursively(double x, double e, int n, double sum) {
    if (fabs(sin(x) - sum) < e) {
        printf("\nRecursion method:\n\nSin(x) = %lf.\nExpression = %lf.\n", sin(x), sum);
        return n;
    }
    
    n++;
    sum += pow(-1, n - 1) * pow(x, 2 * n - 1) / performFactorial(2 * n - 1);
    return сalculateRecursively(x, e, n, sum);
}

int calculateIteratively(double x, double e, int n, double sum) {
    
    while((fabs(sin(x) - sum) > e)){
        n++;
        sum += pow(-1, n - 1) * pow(x, 2 * n - 1) / performFactorial(2 * n - 1);
        
    }
    
    printf("\nIteration method:\n\nSin(x) = %lf.\nExpression = %lf.\n", sin(x), sum);
    return n;
}

int main() {
    double x = 0;
    double e = 0;
    double startTime = 0;
    double endTime = 0;
    char isUserWantToContinue;
    
    while(true){
        printf("Enter x: ");
        scanf("%lf.", &x);
        fflush(stdin);
        
        printf("Enter e: ");
        scanf("%lf", &e);
        fflush(stdin);
        
        printf("Yours choise: x = %lf, e = %lf.\n", x, e);
        
        startTime = clock();
        printf("n = %d.\n", сalculateRecursively(x, e, 1, x));
        endTime = clock();
        printf("It took %lf milliseconds for сalculateRecursively.\n\n", endTime - startTime);
        
        startTime = clock();
        printf("n = %d.\n\n", calculateIteratively(x, e, 1, x));
        endTime = clock();
        printf("It took %lf milliseconds for calculateIteratively.\n\n", endTime - startTime);
        
        printf("If you want continue - enter 'y' into console, otherwise enter any char to exit program.\nYour Choise: ");
        isUserWantToContinue = getchar();
        if(isUserWantToContinue == 'y'){
            continue;
        }
        else{
            return 0;
        }
        
    }
    return 0;
}
