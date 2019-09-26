#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include <signal.h>
#include <sys/wait.h>

int main()
{
	int pid1;
	int td[2];
	int status;

	if (pipe(td) < 0)
	{
		printf("pipe creation failed\n");
		exit(0);
	}

	if (fork() == 0)	//child number 1
	{
		pid1 = getpid();

		int child_pid;

		read(td[0], &child_pid, sizeof(child_pid));	//reading the pid from pipe

		printf("in 2 seconds the child will be terminated\n");
		sleep(2);

		printf("got child %d\n", child_pid);

		kill(child_pid, SIGKILL);	//sends a signal
		printf("killed\n");

		exit(0);
	}
	else
	{
		int pid2 = fork();

		if (pid2 == 0)	//child number 2
		{
			while(1)
			{
				printf("working\n");
				sleep(1);
			}
		}
		else	//parent
		{

			write(td[1], &pid2, sizeof(pid2));	//writes pid to pipe

			pid_t t = waitpid(pid2, &status, 0);
			printf("child process was exited with status %d\n", status);
			exit(1);
		}
	}

	return 0;
}

/*
	sending SIGSTOP signal does not kill the process, it just kinda pauses it, so the process execution stops, but parent process doesn't terminate
	sending SIGKILL signal actually kills the process so the parent terminates
*/