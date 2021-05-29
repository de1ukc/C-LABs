#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>

void dva_chisla(int* w,int g,char temp[100][1000],char teen[10][10],char a)
{
    int tp=0;
    switch(w[g])
      {
          case 0:
              break;

          default:
           if(w[g]==1) tp=1;
           else if(w[g]==2) tp=2;
           else if(w[g]==3) tp=3;
           else if(w[g]==4) tp=4;
           else if(w[g]==5) tp=5;
           else if(w[g]==6) tp=6;
           else if(w[g]==7) tp=7;
           else if(w[g]==8) tp=8;
           else if(w[g]==9) tp=9;
            switch(a)
              {
              case 'i': strcat(temp[g],strcat(teen[tp-1],"ь")); break;
              case 'r': strcat(temp[g],strcat(teen[tp-1],"и")); break;
              case 'd': strcat(temp[g],strcat(teen[tp-1],"и")); break;
              case 'v': strcat(temp[g],strcat(teen[tp-1],"ь")); break;
              case 't': strcat(temp[g],strcat(teen[tp-1],"ью")); break;
              case 'p': strcat(temp[g],strcat(teen[tp-1],"и")); break;
              }
            break;
      }
}
void odno_chislo(int* w,int g,char temp[100][1000],char edin[10][1000],char a)
{
    int tp=0;
    switch(w[g])
    {
    case 1:
        switch(a)
        {
        case 'i': strcat(temp[g],strcat(edin[1-1],"ин")); break;
        case 'r': strcat(temp[g],strcat(edin[1-1],"ного")); break;
        case 'd': strcat(temp[g],strcat(edin[1-1],"ному")); break;
        case 'v': strcat(temp[g],strcat(edin[1-1],"ин")); break;
        case 't': strcat(temp[g],strcat(edin[1-1],"ним")); break;
        case 'p': strcat(temp[g],strcat(edin[1-1],"ном")); break;
        }
        break;

    case 2:
        switch(a)
        {
        case 'i': strcat(temp[g],strcat(edin[2-1],"а")); break;
        case 'r': strcat(temp[g],strcat(edin[2-1],"ух")); break;
        case 'd': strcat(temp[g],strcat(edin[2-1],"ум")); break;
        case 'v': strcat(temp[g],strcat(edin[2-1],"а")); break;
        case 't': strcat(temp[g],strcat(edin[2-1],"умя")); break;
        case 'p': strcat(temp[g],strcat(edin[2-1],"ух")); break;
        }
        break;

    case 3:
        switch(a)
        {
        case 'i': strcat(temp[g],strcat(edin[3-1],"b")); break;
        case 'r': strcat(temp[g],strcat(edin[3-1],"ёх")); break;
        case 'd': strcat(temp[g],strcat(edin[3-1],"ём")); break;
        case 'v': strcat(temp[g],strcat(edin[3-1],"и")); break;
        case 't': strcat(temp[g],strcat(edin[3-1],"емя")); break;
        case 'p': strcat(temp[g],strcat(edin[3-1],"ёх")); break;
        }
        break;

    case 4:
        switch(a)
        {
        case 'i': strcat(temp[g],strcat(edin[4-1],"е")); break;
        case 'r': strcat(temp[g],strcat(edin[4-1],"ёх")); break;
        case 'd': strcat(temp[g],strcat(edin[4-1],"ём")); break;
        case 'v': strcat(temp[g],strcat(edin[4-1],"е")); break;
        case 't': strcat(temp[g],strcat(edin[4-1],"ьмя")); break;
        case 'p': strcat(temp[g],strcat(edin[4-1],"ёх")); break;
        }
        break;

    case 0:
        break;

    default:

        if(w[g]==5) tp=5;
        else if(w[g]==6) tp=6;
             else if(w[g]==7) tp=7;
                  else if(w[g]==8) tp=8;
                       else if(w[g]==9) tp=9;
        switch(a)
        {
        case 'i': strcat(temp[g],strcat(edin[tp-1],"ь")); break;
        case 'r': strcat(temp[g],strcat(edin[tp-1],"и")); break;
        case 'd': strcat(temp[g],strcat(edin[tp-1],"и")); break;
        case 'v': strcat(temp[g],strcat(edin[tp-1],"ь")); break;
        case 't': strcat(temp[g],strcat(edin[tp-1],"ью")); break;
        case 'p': strcat(temp[g],strcat(edin[tp-1],"и")); break;
        }
      break;
    }
}

void desiatki(int* w,int g,char temp[100][1000],char des[10][1000],char a)
{
    int tp=0;
    switch(w[g])
          {
          case 2:
              switch(a)
                {
                case 'i': strcat(temp[g],strcat(des[2-1],"ь")); break;
                case 'r': strcat(temp[g],strcat(des[2-1],"и")); break;
                case 'd': strcat(temp[g],strcat(des[2-1],"и")); break;
                case 'v': strcat(temp[g],strcat(des[2-1],"ь")); break;
                case 't': strcat(temp[g],strcat(des[2-1],"ью")); break;
                case 'p': strcat(temp[g],strcat(des[2-1],"и")); break;
                }
              break;

          case 3:
              switch(a)
                {
                case 'i': strcat(temp[g],strcat(des[3-1],"ь")); break;
                case 'r': strcat(temp[g],strcat(des[3-1],"и")); break;
                case 'd': strcat(temp[g],strcat(des[3-1],"и")); break;
                case 'v': strcat(temp[g],strcat(des[3-1],"ь")); break;
                case 't': strcat(temp[g],strcat(des[3-1],"ью")); break;
                case 'p': strcat(temp[g],strcat(des[3-1],"и")); break;
                }
              break;

          case 4:
              switch(a)
                {
                case 'i': strcat(temp[g],strcat(des[4-1],"")); break;
                case 'r': strcat(temp[g],strcat(des[4-1],"а")); break;
                case 'd': strcat(temp[g],strcat(des[4-1],"а")); break;
                case 'v': strcat(temp[g],strcat(des[4-1],"")); break;
                case 't': strcat(temp[g],strcat(des[4-1],"а")); break;
                case 'p': strcat(temp[g],strcat(des[4-1],"а")); break;
                }
              break;

          case 9:
              switch(a)
                {
                case 'i': strcat(temp[g],strcat(des[9-1],"о")); break;
                case 'r': strcat(temp[g],strcat(des[9-1],"а")); break;
                case 'd': strcat(temp[g],strcat(des[9-1],"а")); break;
                case 'v': strcat(temp[g],strcat(des[9-1],"о")); break;
                case 't': strcat(temp[g],strcat(des[9-1],"а")); break;
                case 'p': strcat(temp[g],strcat(des[9-1],"а")); break;
                }
              break;
          case 0:
              break;

          default:

                if(w[g]==5) tp=5;
                else if(w[g]==6) tp=6;
                else if(w[g]==7) tp=7;
                else if(w[g]==8) tp=8;

                switch(a)
                {
                case 'i': strcat(temp[g],strcat(des[tp-1],"ьдесят")); break;
                case 'r': strcat(temp[g],strcat(des[tp-1],"идесяти")); break;
                case 'd': strcat(temp[g],strcat(des[tp-1],"идесяти")); break;
                case 'v': strcat(temp[g],strcat(des[tp-1],"ьдесят")); break;
                case 't': strcat(temp[g],strcat(des[tp-1],"ьюдесятью")); break;
                case 'p': strcat(temp[g],strcat(des[tp-1],"идесяти")); break;
                }
              break;
          }
}
void sotki(int* w,int g,char temp[100][1000],char sto[10][1000],char a)
{
    int tp=0;
    switch(w[g])
      {
      case 1:
          switch(a)
            {
            case 'i': strcat(temp[g],strcat(sto[1-1],"о")); break;
            case 'r': strcat(temp[g],strcat(sto[1-1],"а")); break;
            case 'd': strcat(temp[g],strcat(sto[1-1],"а")); break;
            case 'v': strcat(temp[g],strcat(sto[1-1],"о")); break;
            case 't': strcat(temp[g],strcat(sto[1-1],"а")); break;
            case 'p': strcat(temp[g],strcat(sto[1-1],"а")); break;
            }
          break;

      case 2:
          switch(a)
            {
            case 'i': strcat(temp[g],strcat(sto[2-1],"ести")); break;
            case 'r': strcat(temp[g],strcat(sto[2-1],"ухсот")); break;
            case 'd': strcat(temp[g],strcat(sto[2-1],"умстам")); break;
            case 'v': strcat(temp[g],strcat(sto[2-1],"ести")); break;
            case 't': strcat(temp[g],strcat(sto[2-1],"умястами")); break;
            case 'p': strcat(temp[g],strcat(sto[2-1],"иухстах")); break;
            }
          break;

      case 3:
          switch(a)
            {
            case 'i': strcat(temp[g],strcat(sto[3-1],"иста")); break;
            case 'r': strcat(temp[g],strcat(sto[3-1],"ёхсот")); break;
            case 'd': strcat(temp[g],strcat(sto[3-1],"ёмстам")); break;
            case 'v': strcat(temp[g],strcat(sto[3-1],"иста")); break;
            case 't': strcat(temp[g],strcat(sto[3-1],"емястами")); break;
            case 'p': strcat(temp[g],strcat(sto[3-1],"ёхстах")); break;
            }
          break;

      case 4:
          switch(a)
            {
            case 'i': strcat(temp[g],strcat(sto[4-1],"еста")); break;
            case 'r': strcat(temp[g],strcat(sto[4-1],"ёхсот")); break;
            case 'd': strcat(temp[g],strcat(sto[4-1],"ёмстам")); break;
            case 'v': strcat(temp[g],strcat(sto[4-1],"еста")); break;
            case 't': strcat(temp[g],strcat(sto[4-1],"ьмястами")); break;
            case 'p': strcat(temp[g],strcat(sto[4-1],"ёхстах")); break;
            }
          break;
            case 0:
        break;
      default:
        if(w[g]==5) tp=5;
        else if(w[g]==6) tp=6;
        else if(w[g]==7) tp=7;
        else if(w[g]==8) tp=8;
        else if(w[g]==9) tp=9;

        switch(a)
        {
        case 'i': strcat(temp[g],strcat(sto[tp-1],"ьсот")); break;
        case 'r': strcat(temp[g],strcat(sto[tp-1],"исот")); break;
        case 'd': strcat(temp[g],strcat(sto[tp-1],"истам")); break;
        case 'v': strcat(temp[g],strcat(sto[tp-1],"ьсот")); break;
        case 't': strcat(temp[g],strcat(sto[tp-1],"ьюстами")); break;
        case 'p': strcat(temp[g],strcat(sto[tp-1],"истах")); break;
        }
      break;
      }
}

void clear (void)
    {
        while ( getchar() != '\n' );
    }

int main(void)
{
    setlocale(0,"");

    char edin[][1000] = {"од", "дв", "тр", "четыр", "пят", "шест", "сем", "восем", "девят"};
    char teen[][1000] = {"одиннадцат", "двенадцат", "тринадцат", "четырнадцат", "пятнадцат", "шестнадцат", "семнадцат", "восемнадцат", "девятнадцат"};
    char des[][1000] = {"-","двадцат", "тридцат", "сорок", "пят", "шест", "сем", "вос", "девяност"};
    char sto[][1000] = {"ст", "дв", "тр", "четыр", "пят", "шест", "сем", "вос", "девят"};

    char temp[10][1000];

    char Arr_Sotki[10][100] = {"","","","","ьюстами","истах"};
    char Arr_Desiatki[10][100];
    char Arr_Odno_Chislo[10][100];
    char Arr_Dva_Chisla[10][100];

    int n,q=1,nx=0,sch=0,w[10000],c,p,g=-1,j=0,hj,f;
    char a;

    printf("Введите n: ");
    scanf("%d",&n);
    printf("\nСимволы падежей:\ni-Именительный(Кто?,Что?)\nr-Родительный(Кого?,Чего?)\nd-Дательный(Кому?,Чему?)\nv-Венительный(Кого?,Что?)\nt-Творительный(Кем?,Чем?)\np-Предложный(О Ком?,О Чем?)\n\n");

    printf("Введите символ падежа a:= ");
    fflush(stdin);
    scanf("%c",&a);

    if(n==0)
    {
        switch(a)
        {
        case 'i': printf("ноль"); break;
        case 'r': printf("ноля"); break;
        case 'd': printf("нолю"); break;
        case 'v': printf("ноль"); break;
        case 't': printf("нолём"); break;
        case 'p': printf("ноле"); break;
        }
        printf("\n");
        return 0;
    }
    else if(n==1000)
    {
        switch(a)
        {
        case 'i': printf("одна тысяча"); break;
        case 'r': printf("одной тысячи"); break;
        case 'd': printf("одной тысяче"); break;
        case 'v': printf("одну тысячу"); break;
        case 't': printf("одной тысячей"); break;
        case 'p': printf("одной тысяче"); break;
        }
        printf("\n");
        return 0;
    }



    c=p=n;

    while(q!=0)
    {
        nx = n % 10;
        n = n / 10;
        if(n == 0) q=0;
        sch++;
        nx=n;
    }

   // printf("Количество цифр в числе = %d\n",sch);

    q=1;
    while(q!=0)
    {
        if((sch!=1) ||(p!=1))
        {
            g++;
            j++;
            //Заносим в массив числа
            if((sch-j)!=0)
            {
                hj=pow(10,(sch-j));
                w[g]= p / hj;
                p = p % hj;
            }
            else
            {
                w[g]= p / 1;
                q=0;
            }
            //--------------------------
        }
        else
        {
            g++;
            w[g]=c;
            q=0;
        }
    }

      if(w[g-1]==1)
      {
          dva_chisla(w,g,temp,teen,a);
          g-=2;
          sotki(w,g,temp,sto,a);
      }
      else if((w[g-1]==0) && (w[g]==0))
      {
            g=0;
            sotki(w,g,temp,sto,a);

            for(int i=0; i<sch; i++)printf("%s ",temp[i]);
            return 0;
      }
      else if(w[g-1]!=1)
      {
          odno_chislo(w,g,temp,edin,a);
          g--;
          desiatki(w,g,temp,des,a);
          g--;
          sotki(w,g,temp,sto,a);
      }


    printf("\n");
    for(int i=0; i<sch; i++)printf("%s ",temp[i]);
    printf("\n");

    return 0;
}
