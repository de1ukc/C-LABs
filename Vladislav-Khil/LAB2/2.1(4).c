//Задание 2.1 Вариант 4

/*Разработать программу, меню которой позволяет выполнить следующие функции:
1. Вввод даты (число, месяц, год)
2. Ввод даты в форме: 1 января 2010
3. Ввод даты в форме: 01.01.10
4. Вычисление по дате дня недели и порядкового номера дня в году
5. Вывод количества дней, прошедших от Рождества Христова до введёной даты
6. Информация о версии и авторе программы
7. Выход из программы*/

#include <stdio.h>
#include <math.h>
#include <stdbool.h>

int CheckingInput(int day, int month, int year) {
    if (year < 0 || day <= 0 || month <= 0) {
        return 0;
    }
    if (month > 12) {
        return 0;
    }
    if (month == 2) {
        if (year % 4 == 0) {
            if (day <= 29) {
                return 1;
            }
            else {
                return 0;
            }
        }
        else {
            if (day <= 28) {
                return 1;
            }
            else {
                return 0;
            }
        }
    }
    if (month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12) {
        if (day <= 31) {
            return 1;
        }
        else {
            return 0;
        }
    }
    if (month == 4 || month == 6 || month == 9 || month == 11) {
        if (day <= 30) {
            return 1;
        }
        else {
            return 0;
        }
    }
}

void DataInTheFormatDDMMYY(int day, int month, int year) {
    int year_yy = year % 100;
    if (year_yy < 10) {
        if (month < 10 && day < 10) {
            printf("input is 0%d.0%d.0%d.\n", day, month, year_yy);
        }
        if (month < 10 && day >= 10) {
            printf("input is %d.0%d.0%d.\n", day, month, year_yy);
        }
        if (month >= 10 && day >= 10) {
            printf("input is %d.%d.0%d.\n", day, month, year_yy);
        }
        if (month >= 10 && day < 10) {
            printf("input is 0%d.%d.0%d.\n", day, month, year_yy);
        }
    }
    else {
        if (month < 10 && day < 10) {
            printf("input is 0%d.0%d.%d.\n", day, month, year_yy);
        }
        if (month < 10 && day >= 10) {
            printf("input is %d.0%d.%d.\n", day, month, year_yy);
        }
        if (month >= 10 && day >= 10) {
            printf("input is %d.%d.%d.\n", day, month, year_yy);
        }
        if (month >= 10 && day < 10) {
            printf("input is 0%d.%d.%d.\n", day, month, year_yy);
        }
    }
}

void DataByWords(int day, int month, int year) {
    switch (month) {
    case 1:
        printf("\ninput is %d january %d y.\n", day, year);
        break;
    case 2:
        printf("\ninput is %d february %d y.\n", day, year);
        break;
    case 3:
        printf("\ninput is %d march %d y.\n", day, year);
        break;
    case 4:
        printf("\ninput is %d april %d y.\n", day, year);
        break;
    case 5:
        printf("\ninput is %d may %d y.\n", day, year);
        break;
    case 6:
        printf("\ninput is %d june %d y.\n", day, year);
        break;
    case 7:
        printf("\ninput is %d july %d y.\n", day, year);
        break;
    case 8:
        printf("\ninput is %d augast %d y.\n", day, year);
        break;
    case 9:
        printf("\ninput is %d september %d y.\n", day, year);
        break;
    case 10:
        printf("\ninput is %d october %d y.\n", day, year);
        break;
    case 11:
        printf("\ninput is %d november %d y.\n", day, year);
        break;
    case 12:
        printf("\ninput is %d december %d y.\n", day, year);
        break;
    }
}

int AmountOfDaysAfterChrist(int day, int month, int year) {
    int totalSum;
    totalSum = year / 4 * 366 + (year - year / 4) * 365;
    int i;
    for (i = 0; i < month; i++) {
        if (i == 2) {
            if (year % 4 == 0) {
                totalSum += 29;
            }
            else {
                totalSum += 28;
            }
        }
        if (i == 1 || i == 3 || i == 5 || i == 7 || i == 8 || i == 10 || i == 12) {
            totalSum += 31;
        }
        if (i == 4 || i == 6 || i == 9 || i == 11) {
            totalSum += 30;
        }
    }

    totalSum += day;
    return totalSum;
}

int OrdinalNumberInTheYear(int day, int month, int year) {
    int sum = 0;
    int i;
    for (i = 0; i < month; i++) {
        if (i == 2) {
            if (year % 4 == 0) {
                sum += 29;
            }
            else {
                sum += 28;
            }
        }
        if (i == 1 || i == 3 || i == 5 || i == 7 || i == 8 || i == 10 || i == 12) {
            sum += 31;
        }
        if (i == 4 || i == 6 || i == 9 || i == 11) {
            sum += 30;
        }
    }
    sum += day;
    return sum;
}

void DayOfTheWeek(int day, int month, int year) {
    int date1 = AmountOfDaysAfterChrist(11, 4, 2021); /*Monday*/
    int date2 = AmountOfDaysAfterChrist(day, month, year);
    int difference = (date1 - date2);
    difference = (difference % 7 + 7) % 7;
    switch (difference) {
    case 0:
        printf("\nMonday\n");
        break;
    case 1:
        printf("\nSunday\n");
        break;
    case 2:
        printf("\nSutarday\n");
        break;
    case 3:
        printf("\nFriday\n");
        break;
    case 4:
        printf("\nThursday\n");
        break;
    case 5:
        printf("\nWednesday\n");
        break;
    case 6:
        printf("\nTuesday\n");
        break;
    default:
        printf("\nSomething goes wrong :(((\n");
        break;
    }

}

int main() {
    char myCase;
    int day = 0, month = 0, year = 0;
    bool boolCheck = true;

    while (boolCheck)
    {
        printf("\nEnter a number of operation, that you want to execute");
        printf("\n1 - to enter a data");
        printf("\n2 - get the data in the format DD.MM.YY.");
        printf("\n3 - get the data in the format 1 january 2010 y.");
        printf("\n4 - the ordinal number in the year and the day of the week");
        printf("\n5 - days, that had passed before Christ");
        printf("\n6 - get information about the auther");
        printf("\n7 - to leave a programm\n");
        while (getchar() != '\n') {};
        scanf_s("%c", &myCase);
        switch (myCase) 
        {
        case '1':
            printf("\nEnter a day, a month, a year, use format DD,MM,YYYY\n");
            while (scanf_s("%d,%d,%d", &day, &month, &year) != 3 || CheckingInput(day, month, year) == 0) 
            {
                printf("\nincorrect input\n");
                while (getchar() != '\n') {}
            }
            printf("\nInput is correct, choose the other operation\n");
            break;
        case '2':
            if (day > 0) {
                DataInTheFormatDDMMYY(day, month, year);
            }
            else {
                printf("firstly, you must do point 1\n");
            }
            break;
        case '3':
            if (day > 0) {
                DataByWords(day, month, year);
            }
            else {
                printf("firstly, you must do point 1\n");
            }
            break;
        case '4':
            if (day > 0) {
                int sum = OrdinalNumberInTheYear(day, month, year);
                printf("The ordinal number of the day is %d\nthe day of the week is ", sum);
                DayOfTheWeek(day, month, year);
            }
            else {
                printf("firstly, you must do point 1\n");
            }
            break;
        case '5':
            if (day > 0) {
                int sum = AmountOfDaysAfterChrist(day, month, year);
                printf("Amount of the days, that passed after Christ is %d days\n", sum);
            }
            else {
                printf("firstly, you must do point 1\n");
            }
            break;
        case '6':
            printf("Program was created by Khil Vladislav, student of group 053506\n");
            break;
        case '7':
            boolCheck = 0;
            break;
        default:
            break;
        }
    }
    return 0;
}