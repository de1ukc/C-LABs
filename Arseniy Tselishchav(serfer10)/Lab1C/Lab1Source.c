#include <stdio.h>


int main()
{
	int firstN;
	int secondN;;
	int max=0;
	int maxN;
	int counter;
	int d;
	printf("Enter first number: ");
	scanf_s("%d", &firstN);
	printf("enter second number: ");
	scanf_s("%d", &secondN);
	if (firstN > secondN)
	{
		printf("First number should be smaller than second");
		return 0;
	}
	for (; firstN<=secondN; firstN++)
	{
		counter = 0;
		int cnt = firstN;
		while (cnt)
		{
			d = cnt % 2;
			if (d == 1)
			{
				counter++;
			}
			cnt = cnt / 2;
		}

		if (max < counter)
		{
			max = counter;
			maxN = firstN;
		}
	}
	printf("counter: %d\nnumber: %d", max,maxN);
	return 0;
}