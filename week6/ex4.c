#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include <signal.h>

void sigkill_handler(int sig)
{
	printf("you want to kill me\n");
}

void sigstop_handler(int sig)
{
	printf("you want to stop me\n");
}

void sigusr_handler(int sig)
{
	printf("idk what does this signal mean\n");
}

int main()
{
	signal(SIGKILL, sigkill_handler);
	signal(SIGSTOP, sigstop_handler);
	signal(SIGUSR1, sigusr_handler);
	while(1);
	return 0;
}

/*
	by the kill command the signal is sent, handled by the program and the corresponding output is out
*/