#include <stdio.h>
#include <sys/types.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>

#define MAX_SIZE 100

char *read_line()
{
	char *line = (char *)malloc(sizeof(char) * MAX_SIZE);
	char c = 'a';
	int ind = 0;
	while (1)
	{
		if (ind >= MAX_SIZE)
		{
			printf("You are too wordy\n");
			exit(0);
		}
		c = getchar();
		if (c == '\n')
		{
			line[ind] = '\0';
			return line;
		}
		else
		{
			line[ind] = c;
		}
		ind++;
	}
}

void shell()
{
	char *line;
	int ok = 1;

	do
	{
		printf("> ");
		line = read_line();
		if (strcmp(line, "q\0") == 0)
		{
			printf("So long and thanks for all the fish\n");
			ok = 0;
		}
		else
		{
			system(line);
		}
	}
	while (ok);
}

int main()
{
	printf("Welcome to da best shell eva. If you want to exit, enter q.\n");
	shell();

	return 0;
}

/*
Output:
Welcome to da best shell eva. If you want to exit, enter q.
> ls
ex1.c	 ex1.sh   ex2_1.out  ex2_2.c	ex2_2.sh  ex3-4.out
ex1.out  ex2_1.c  ex2_1.sh   ex2_2.out	ex3-4.c
> mkdir somedir
> ls
ex1.c	 ex1.sh   ex2_1.out  ex2_2.c	ex2_2.sh  ex3-4.out
ex1.out  ex2_1.c  ex2_1.sh   ex2_2.out	ex3-4.c   somedir
> rmdir somedir
> ls
ex1.c	 ex1.sh   ex2_1.out  ex2_2.c	ex2_2.sh  ex3-4.out
ex1.out  ex2_1.c  ex2_1.sh   ex2_2.out	ex3-4.c
> ps
  PID TTY          TIME CMD
 6624 pts/0    00:00:00 ex3-4.out
 6773 pts/0    00:00:00 sh
 6774 pts/0    00:00:00 ps
30107 pts/0    00:00:00 fish
31336 pts/0    00:00:00 bash
> ./ex3-4.out
Welcome to da best shell eva. If you want to exit, enter q.
> echo "this is my shell running inside my shell"
this is my shell running inside my shell
> q
So long and thanks for all the fish
> q
So long and thanks for all the fish

*/