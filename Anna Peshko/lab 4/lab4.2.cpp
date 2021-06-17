//Task 4.2 Variant 2

/*Текст в файле содержит многократно вложенные круглые скобки.
Если баланс скобок соблюден, исправить текст, оставив скобки
первого уровня круглыми, второго – заменить на квадратные,
третьего и последующих – на фигурные.*/

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>


bool check(char str[])
{
	int counter = 0;
	for (int i = 0; str[i] != '\0'; i++)
	{
		if (str[i] == '(')
			counter++;
		if (str[i] == ')')
			counter--;
	}
	if (counter != 0) {
		printf("the balance of the brackets is not met");
		return false;
	}
	return true;
}

void edit(char str[], int& count, int& maxLeinght) {
	for (int i = 0; str[i] != '\0'; i++)
	{
		if (str[i] == '(')
		{
			str[i] = '{';
			count++;
			if (count > maxLeinght)
			{
				maxLeinght = count;
			}
		}
		if (str[i] == ')')
		{
			str[i] = '}';
			count--;
		}
	}

	for (int i = 0; str[i] != '\0'; i++)
	{
		if (str[i] == '{')
		{
			count++;
			if (count == maxLeinght) str[i] = '(';
			if (count == maxLeinght - 1) str[i] = '[';
		}
		if (str[i] == '}')
		{
			if (count == maxLeinght) str[i] = ')';
			if (count == maxLeinght - 1) str[i] = ']';
			count--;
		}
	}
}


int main(FILE* fp)
{
	char* string = (char*)calloc(255, 1);
	int count = 0, maxLeinght = 0;

	FILE* my_file;
	my_file = fopen("input.txt", "r");
	if (my_file == NULL)
	{
		printf("error");
	}
	while (fgets(string, 50, my_file) != NULL) {}
	printf("%s", string);
	fclose(my_file);
		
	if (check(string)) {
		edit(string, count, maxLeinght);
		puts(string);
	}

	free(string);
}