#include <stdio.h>
#include <windows.h>

int main()
{
    SetConsoleOutputCP(CP_UTF8);
    int pole, first, norma, season, years = 1, full, received;
    printf("Введите первоначальное количество семян: ");
    scanf("%d", &first);
    printf("Сколько семян собирают за сезон: ");
    scanf("%d", &season);
    printf("Размер поля: ");
    scanf("%d", &pole);
    printf("Норма высадки: ");
    scanf("%d", &norma);
    full = pole * norma;
    received = first*season;
    while(received < full)
    {
        received = received*season;
        years++;
    }
    printf("Необходимо лет: ", &years);
    printf("%d", years);
    return 0;
}