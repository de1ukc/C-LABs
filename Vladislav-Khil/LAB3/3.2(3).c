//Задание 3.2 Вариант 3
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <stdbool.h>

#define STR_MAX_SIZE 100

int main()
{
    bool isCorrect = true;
    while (isCorrect)
    {
        int size = 0;
        char K;
        system("cls");
        printf("1.Encrypt message\n2.Decrypt message\n3.Exit the program\n");
        scanf_s("%c", &K);
        switch (K)
        {
            case '1':
            {
                system("cls");
                char* str = (char*)malloc(STR_MAX_SIZE * sizeof(char));
                char* str2 = (char*)malloc(STR_MAX_SIZE * sizeof(char));
                printf("Write string you want to encrypt: ");
                while ((getchar()) != '\n');
                fgets(str, STR_MAX_SIZE, stdin);
                str[strlen(str) - 1] = '\0';
                while(size * size < strlen(str))
                {
                    size++;
                }
                for (int i = 0; i < size * size; i++)
                {
                    if (i < strlen(str))
                    {
                        str2[i] = str[i];
                    }
                    else
                    {
                        str2[i] = ' ';
                    }
                }
                str2[size * size] = '\0';
                char **matrix = (char**)malloc(size * sizeof(char*));
                for (int i = 0; i < size; i++) 
                {
                    matrix[i] = (char*)malloc(size * sizeof(char));
                }
                int k = 0, s = 1;
                for (int j = 0; j < size * size; s++)
                {
                    for (int i = s - 1; i < size - (s - 1); i++, j++)
                    {
                        matrix[i][s - 1] = str2[k];
                        k++;
                    }
                    for (int i = s; i < size - (s - 1); i++, j++)
                    {
                        matrix[size - s][i] = str2[k];
                        k++;
                    }
                    for (int i = size - (s + 1); i >= s - 1; i--, j++)
                    {
                        matrix[i][size - s] = str2[k];
                        k++;
                    }
                    for (int i = size - (s + 1); i >= s; i--, j++)
                    {
                        matrix[s - 1][i] = str2[k];
                        k++;
                    }
                }
                for (int i = 0; i < size; i++)
                {
                    for (int j = 0; j < size; j++)
                    {
                        printf("%c", matrix[i][j]);
                    }
                    printf("\n");
                }
                free(str);
                free(str2);
                printf("\nPress any button...");
                _getch();
                break;
            }
            case '2':
            {
                system("cls");
                printf("How many strings are in message?\n");
                scanf_s("%d", &size);
                if (size < 1 || size > 100)
                {
                    printf("Wrong input");
                    _getch();
                    continue;
                }
                while ((getchar()) != '\n');
                char** str = (char**)malloc(size * sizeof(char*));
                for (int i = 0; i < size; i++)
                {
                    str[i] = (char*)malloc(STR_MAX_SIZE * sizeof(char));
                }
                for (int i = 0; i < size; i++)
                {
                    fgets(str[i], STR_MAX_SIZE, stdin);
                    str[i][strlen(str[i]) - 1] = '\0';
                }
                char* str2 = (char*)malloc(STR_MAX_SIZE * sizeof(char));
                int k = 0, s = 1;
                for (int j = 0; j < size * size; s++)
                {
                    for (int i = s - 1; i < size - (s - 1); i++, j++)
                    {
                        str2[k] = str[i][s - 1];
                        k++;
                    }
                    for (int i = s; i < size - (s - 1); i++, j++)
                    {
                        str2[k] = str[size - s][i];
                        k++;
                    }
                    for (int i = size - (s + 1); i >= s - 1; i--, j++)
                    {
                        str2[k] = str[i][size - s];
                        k++;
                    }
                    for (int i = size - (s + 1); i >= s; i--, j++)
                    {
                        str2[k] = str[s - 1][i];
                        k++;
                    }
                }
                str2[k] = '\0';
                printf("\nDecrypted string:\n%s", str2);
                for (int i = 0; i < size; i++)
                {
                    free(str[i]);
                }
                free(str);
                free(str2);
                printf("\nPress any button...");
                _getch();
                break;
            }
            case '3':
            {
                system("cls");
                isCorrect = false;
                printf("The end");
            }
            default:
            {
                break;
            }
        }
    }
}