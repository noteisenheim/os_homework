#include <stdio.h>
#include <stdlib.h>

int main()
{
	int n;
	printf("Enter the height of the triangle: \n");
	scanf("%d", &n);

	for(int i = 1; i <= (2 * n - 1); i += 2)
	{
		for(int j = 0; j < (2 * n - 1 - i)/2; j++)
		{
			printf(" ");
		}
		for (int j = 0; j < i; j++)
		{
			printf("*");
		}
		for(int j = 0; j < (2 * n - 1 - i)/2; j++)
		{
			printf(" ");
		}
		printf("\n");
	}

	return 0;
}