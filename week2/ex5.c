#include <stdio.h>
#include <stdlib.h>

void print_triangle(int n)
{
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
}

void print_rectangle(int n)
{
	for(int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			printf("*");
		}
		printf("\n");
	}
}

void print_right_triangle(int n)
{
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= i; j++)
		{
			printf("*");
		}
		printf("\n");
	}
}

void print_rotated_triangle(int n)
{
	for(int i = 1; i < n; i++)
	{
		for (int j = 0; j < i; j++)
		{
			printf("*");
		}
		printf("\n");
	}
	for(int i = n; i >= 0; i--)
	{
		for (int j = 0; j < i; j++)
		{
			printf("*");
		}
		printf("\n");
	}
}

int main()
{
	int n;
	printf("Enter the height of the figure: \n");
	scanf("%d", &n);

	int type;
	printf("If you want to print the right triangle, enter 1\nIf you want to print an isosceles triangle, enter 2\nIf you want to print a rectangle, enter 3\nIf you want to print the rotated triangle, enter 4\n");
	scanf("%d", &type);
	if (type == 1)
	{
		print_right_triangle(n);
	}  
	else if (type == 2)
	{
		print_triangle(n);
	}
	else if (type == 3)
	{
		print_rectangle(n);
	}
	else if (type == 4)
	{
		print_rotated_triangle(n);
	}

	return 0;
}