#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
//var 2.1(11)

int a; // действительная часть комплексного числа
char symbol;
int b; // мнимая часть комплексного числа
const char i = 'i';

void entering(){
    printf("Enter you complex number(like this 10+7i): ");
 char s[100];
 scanf("%s",s);
    int pos = 0;
    a = 0;
    b = 0;
    symbol = '+';
   // i = 'i';
    bool below__zero = 0;
    if(s[pos] == '-') below__zero = 1, pos++;
    int x = 0;
    while(s[pos] >= '0' && s[pos] <= '9'){
        x = x * 10 + s[pos] - '0';
        pos++;
    }
    if(below__zero) x *= -1;
    bool reverse = 0;
    if(s[pos] == 'i'){
        b = x;
        pos++;
        reverse = 1;
    } else a = x;
    below__zero = 0;
    if(s[pos] == '+' || s[pos]  == '-'){
        symbol = s[pos];
        if(reverse) {
            if(s[pos] == '-') below__zero = 1, symbol = ' ';
         }
        pos++;
    } else {
        if(b < 0) symbol = ' ';
        return;
    }

    if(s[pos] == '-') below__zero = 1, pos++;
    x = 0;
    while(s[pos] >= '0' && s[pos] <= '9'){
        x = x * 10 + s[pos] - '0';
        pos++;
    }
    if(below__zero) x *= -1;
    if(!reverse) b = x;
        else a = x;

}

void coutt (){
printf("%s%d%c%d%c","y= ",a,symbol,b,i);
printf("\n");
}

void info(){
printf("This program was created by Aleh Asadchy. Version 4.0");
printf("\n");

}

void bnpow(){
int degree;
printf("%s","Enter degree : ");
scanf("%d",&degree);
if (degree == 0 ) printf("%s"," z^0 = 1");
if (degree == 1) coutt();
else
    {
    float r;
    r = sqrt((a*a)+(b*b));
    float new_r = pow(r,degree);
    float cos_a = a / r;
    float sin_a = b / r;
    float cos_aa = cos(acos(cos_a)*degree);
    float sin_aa = sin(asin(sin_a)*degree);
    printf("%s%f%s%f%c%c%c%c%f%c"," z^n = ",new_r," * ( ",cos_aa,symbol,' ',i,'*',sin_aa,')');
    printf("\n");
    }
}

void sopr(){
    char buff_symb = '+';
    if (symbol == '+') buff_symb = '-';
    printf("%s","conjugate complex number : ");
    printf("%s%d%c%d%c","y= ",a,buff_symb,b,i);
    printf("\n");
}

void triga(){
float r;
r = sqrt((a*a)+(b*b));
float cos_a = a / r;
float sin_a = b / r;
if (sin_a < 0){symbol = '-';sin_a *= -1;}
printf("%s","z = e^i*f * r");
printf("\n");
printf("%s%f","r = ",r);
printf("\n");
printf("%s%f","cos(f) = ",cos_a);
printf("\n");
printf("%s%f","sin(f) = ",sin_a);
printf("\n");
printf("%s%s%f%c%c%c%c%s%f%s","e^i*f = "," ( ",cos_a,' ',symbol,' ',i," * ",sin_a," ) ");
printf("\n");
printf("%s%s%c%f","z = "," e^i*f ",'*',r);
printf("\n");

}

int Menu(){
    int i;
    printf("\n");
    printf("What are we gonna do?\n");
    printf("1.Enter complex number. \n");
    printf("2.Show algebraicheskuyu formu\n");
    printf("3.Show pokazatelnuyu formu\n");
    printf("4.Sopryazhonnoe complexnoe chislo \n");
    printf("5.Bin power?\n");
    printf("6.Info \n");
    printf("7.Exit\n");
    printf("\n");
    scanf("%i",&i);
    printf("\n");
    return i;
}

int main()
{
   while (1){
        switch (Menu()) {
            case 1 :entering(); if (symbol == '-'){b*=-1;symbol = '+';} break;
            case 2 : coutt(); break;
            case 3 : triga();break;
            case 4 : sopr();break;
            case 5 : bnpow();break;
            case 6 : info(); break;
            case 7 : printf("Bye, see you later mate\n"); return 0;
            default : printf("You are a bold one. Try again!");printf("\n");return 0; break;
        }

   }
return 0;
}
/*
10 + 7i
*/
