#include <stdio.h>

void bubble_sort(int (*a)[], int len, int (*comp)(int, int));

int simple_comparator(int a, int b)
{
	if (a < b)
	{
		return 1;
	}
	
	return 0;
}

int main()
{
	int (*comp_func)(int, int) = &simple_comparator;
	int a[] = {4, 5, 3, 7, 1, 2, 6};

	int len = sizeof(a) / sizeof(a[0]);

	printf("Initial array is: ");
	for (int i = 0; i < len; i++)
	{
		printf("%d ", a[i]);
	}
	printf("\n");

	bubble_sort(&a, len, comp_func);

	printf("Resulting array is: ");
	for (int i = 0; i < len; i++)
	{
		printf("%d ", a[i]);
	}	

	return 0;
}

void bubble_sort(int (*a)[], int len, int (*comp)(int, int))
{
	for (int i = 0; i < (len - 1); i++)
	{
		for(int j = 0; j < (len - i - 1); j++)
		{
			if (!(*comp)((*a)[j], (*a)[j+1]))
			{
				int temp = (*a)[j];
				(*a)[j] = (*a)[j+1];
				(*a)[j+1] = temp;
			}
		}
	}
}
