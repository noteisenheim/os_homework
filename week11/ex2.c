#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/mman.h>
#include <string.h>

int main()
{
	char *text = "Hello";
	int textsize = strlen(text) + 1;

	//create buffer
	char buff[textsize];
	memset(buff, '\0', sizeof(buff));
	setvbuf(stdout, buff, _IOLBF, textsize);

	//printing, saving to buffer
	for(int i = 0; i < (textsize - 1); i++)
	{
		printf("%c", text[i]);
		sleep(1);
	}

	//send to buffer signal for output
	printf("\n");

	return 0;
}