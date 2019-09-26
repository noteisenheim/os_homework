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
		if (fork())	//parent process
		{
			close(td[0]);	//close input
			write(td[1], some_text, strlen(some_text) * sizeof(char));
		}
		else	//child process
		{
			close(td[1]);	//close output
			should_be_empty = malloc(MAX_LEN * sizeof(char));
			read(td[0], should_be_empty, MAX_LEN * sizeof(char));
			printf("%s\n", should_be_empty);
		}
	}
	else
	{
		printf("Creation failed\n");
	}

	return 0;
}