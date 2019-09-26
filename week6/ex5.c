#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include <signal.h>

int main()
{
	if (fork() == 0)
	{
		while(1)
		{
			printf("i am alive\n");
			sleep(1);
		}
	}

	else
	{
		sleep(10);
		kill(0, SIGTERM);
	}

	return 0;
}