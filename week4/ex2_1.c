#include <stdio.h>
#include <sys/types.h>
#include <string.h>
#include <unistd.h>

#define BUF_SIZE 100

int main()
{
	char buf[BUF_SIZE];

	for (int i = 0; i < 3; i++)
	{
		fork();
		sleep(5);
	}

	return 0;
}

/*
Output:
first
ex2_1.out───ex2_1.out
second
ex2_1.out─┬─ex2_1.out───ex2_1.out
          └─ex2_1.out
third
ex2_1.out─┬─ex2_1.out─┬─ex2_1.out───ex2_1.out
          │           └─ex2_1.out
          ├─ex2_1.out───ex2_1.out
          └─ex2_1.out

Each for iteration creates a copy for each already running process, so after the first iteration there are 2 processes running, after second - 4 and after the third - 8
*/