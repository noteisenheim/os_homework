#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>

#define MAX_LEN 100

int main()
{
	char *some_text = "i cannot understand os\0";
	char *should_be_empty = "";

	int td[2];

	if (pipe(td) == 0)	//if pipe was successfully created
	{
		write(td[1], some_text, strlen(some_text) * sizeof(char));	//save input to the pipe
		should_be_empty = malloc(MAX_LEN * sizeof(char));
		read(td[0], should_be_empty, MAX_LEN * sizeof(char));	//write pipe's input to the output
	}
	else
	{
		printf("Creation failed\n");
	}
	printf("%s\n", should_be_empty);

	return 0;
}