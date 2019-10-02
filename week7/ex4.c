#include <stdlib.h>
#include <stdio.h>
#include <string.h>

void *da_best_realloc(void *ptr, int bytes)
{
	if (ptr == NULL)
	{
		return malloc(bytes);
	}
	if (bytes == 0)	//if no memory should be allocated
	{
		free(ptr);
		return NULL;
	}

	void *newptr = malloc(bytes);	//allocate a new memory
	memcpy(newptr, ptr, bytes);	//copy the old contents
	free(ptr);	//deallocate memory
	return newptr;
}

int main()
{
	int *a = (int *)calloc(5, sizeof(int));	//allocating memory for array of len 5
	for (int i = 0; i < 5; i++)
	{
		a[i] = i;
	}

	a = (int *)da_best_realloc(a, sizeof(int) * 7);	//reallocating for the len 7 using my function

	for (int i = 0; i < 7; i++)
	{
		printf("%d ", a[i]);
	}

	return 0;
}