#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LENGTH 100

int main()
{
	char string[MAX_LENGTH];
	printf("Enter the input string: \n");
	fgets(string, MAX_LENGTH, stdin);

	for(int i = (strlen(string) - 1); i >=0; i--)
	{
		printf("%c", string[i]);
	}
	printf("\n");
	return 0;
}