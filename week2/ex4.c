#include <stdio.h>
#include <stdlib.h>

void swap(int *x, int *y)
{
	int g;
	g = *x;
	*x = *y;
	*y = g;
	printf("Swapped successfully!\n");
}

int main()
{
	int a, b;

	printf("Enter the first integer: \n");
	scanf("%d", &a);
	printf("Enter the second integer: \n");
	scanf("%d", &b);

	swap(&a, &b);

	printf("a = %d\n", a);
	printf("b = %d\n", b);

	return 0;
}