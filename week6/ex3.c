#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include <signal.h>

void handler(int sig)
{
	printf("i've noticed you doing some things you shouldn't do\n");
}

int main()
{
	signal(SIGINT, handler);
	while(1);
	return 0;
}