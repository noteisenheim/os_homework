#include <stdio.h>
#include <sys/types.h>
#include <string.h>
#include <unistd.h>

#define BUF_SIZE 100

int main()
{
	char buf[BUF_SIZE];

	int n = 17;

	int pid = fork();

	if (pid != 0)
	{
		sprintf(buf, "Hello from parent [%d - %d]\n", getpid(), n);
		write(1, buf, strlen(buf));
	}
	else
	{
		sprintf(buf, "Hello from child [%d - %d]\n", getpid(), n);
		write(1, buf, strlen(buf));
	}

	return 0;
}

/*
My output is:
1
Hello from parent [3928 - 17]
Hello from child [3929 - 17]
2
Hello from parent [3930 - 17]
Hello from child [3931 - 17]
3
Hello from parent [3932 - 17]
Hello from child [3933 - 17]
4
Hello from parent [3934 - 17]
Hello from child [3935 - 17]
5
Hello from parent [3936 - 17]
Hello from child [3937 - 17]
6
Hello from parent [3938 - 17]
Hello from child [3939 - 17]
7
Hello from parent [3940 - 17]
Hello from child [3941 - 17]
8
Hello from parent [3942 - 17]
Hello from child [3943 - 17]
9
Hello from parent [3944 - 17]
Hello from child [3945 - 17]
10
Hello from parent [3946 - 17]
Hello from child [3947 - 17]


Every time I call fork() the new process is created and execute all the commands after the fork (the same does the parent process)
The PID changes, but variable n remains the same

*/