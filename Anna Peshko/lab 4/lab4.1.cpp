//Task 4.1 Variant 2

/*По правилам машинописи после запятой, двоеточия и точки с
запятой в тексте всегда ставится пробел. После восклицательного,
вопросительного знака и точки должен стоять пробел, а затем текст
начинается с заглавной буквы. Составить программу исправления
такого типа ошибок в тексте.*/

#include <stdio.h>

char NewString(char str[], int a, int b);

void main(void) {
	int i = 0;

	int pos = 0;
	char str[256], symb;
	printf("Enter string:\n");
	for (i; (symb = getchar()) != '\n'; i++) {
		str[i] = symb;
	}
	str[i] = '\0';
	for (int j = 0; str[j] != '\0'; j++)
		pos = j + 1;
	for (int j = 0; str[j] != '\0'; j++) {
		if (str[j] == '.' || str[j] == ';' || str[j] == '?' || str[j] == ':' || str[j] == '!' || str[j] == ',') {
			j++;
			if (str[j] >= 97 && str[j] <= 122 && (str[j - 1] == '.' || str[j - 1] == '!' || str[j - 1] == '?'))
			{
				str[j] = str[j] - 32;
			}
			if (str[j] != ' ') {
				pos++;
				NewString(str, j, pos);
			}
		}
	}
	printf("%s", str);
}

char NewString(char str[], int a, int k) {
	int f = a;
	for (k; k > a; k--)
		str[k] = str[k - 1];
	str[f] = ' ';
	return *str;
}