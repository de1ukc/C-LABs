#include <stdio.h>
#include <stdlib.h>

// var 1.2 (19)
int main(){
    int n;
    while (1){
        printf("Enter the number: ");
        scanf("%d", &n);
        int a = 0, b = 0;
        if(n < 8) {
            printf("Incorrect enter!");
            exit(0);
    }
    while(n % 3 != 0){
        b++;
        n -= 5;
    }
    a += n/ 3;
/*
        int k;       //если нужно вз€ть за большинство п€тЄрки(100 дл€ примера)
        k = a / 5;
        a -= k * 5;
        b += k * 3;
*/
    printf("%s", "Treshek: ");
    printf("%d", a);
    printf("%s", "\nPyatereshek: ");
    printf("%d", b);
    printf("\n ");
    }
}
