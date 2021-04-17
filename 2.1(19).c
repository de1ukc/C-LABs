#include<bits.h>
const double stavka = 0.1275;
double balance = 0;
int isOpen = 0;
void Init() {
    printf("Initial sum: ");
    scanf("%lf", &balance);
    if(balance < 0) {
        printf("%s", "Incorrect Enter\n");
        return;
    }
    isOpen = 1;
}
void Add() {
    if(isOpen == 0) {
        printf("%s", "You don`t have a account!\n");
        return;
    }
    printf("How much ? : ");
    double x;
    if(x < 0 ) {
        printf("%s", "Incorrect Enter\n");
        return;
    }
    scanf("%lf", &x);
    balance += x;
}
void View() {
    if(isOpen == 0) {
        printf("%s", "You don`t have a account!\n");
        return;
    }
    printf("%s%lf", "Your balance : ", balance);
}
void ViewByDay() {
    if(isOpen == 0) {
        printf("%s", "You don`t have a account!\n");
        return;
    }
    printf("Enter day: ");
    int k;
    scanf("%d", &k);

    if(k < 0) {
        printf("%s", "Incorrect Enter\n");
        return;
    }
    double buf = balance;
    while(k - 30 >= 0) {
        buf += buf * (stavka / 12.);
        k -= 30;
    }
    printf("%s%lf%c", "Prediction balance : ", buf, '\n');
}
int main() {
    while(1){
        printf("%s", "\nMenu:\n1)Init\n2)Add\n3)View\n4)View by day\n5)Close\n6)Contacts\n7)Exit.\nChoose: ");
        int f;
        scanf("%d", &f);
        switch(f) {
            case 1 :
                Init();
                break;
            case 2 :
                Add();
                break;
            case 3 :
                View();
                break;
            case 4 :
                ViewByDay();
                break;
            case 5 :
                balance = 0;
                isOpen = 0;
                break;
            case 6 :
                printf("%s", "Bank Lab po c\n Konoplich.B.A\n");
                break;
            case 7 :
                return 0;
            default: printf("%s", "Incorrect enter!!!\n");

        }
    }
}
