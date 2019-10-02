#include <stdlib.h>
#include <stdio.h>

int main()
{
	int N;
	printf("enter the size of an array: \n");
	scanf("%d", &N);

	int *array = (int *)calloc(N, sizeof(int));	//memory allocation
	for (int i = 0; i < N; i++)	//array filling
	{
		array[i] = i;
	}

	for (int i = 0; i < N; i++)	//printing
	{
		printf("%d ", array[i]);
	}

	free(array);	//memory deallocating

	return 0;
}