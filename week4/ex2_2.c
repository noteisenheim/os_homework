#include <stdio.h>
#include <sys/types.h>
#include <string.h>
#include <unistd.h>

#define BUF_SIZE 100

int main()
{
	char buf[BUF_SIZE];

	for (int i = 0; i < 5; i++)
	{
		fork();
		sleep(3);
	}

	return 0;
}

/*
Output:
first
ex2_2.out───ex2_2.out
second
ex2_2.out─┬─ex2_2.out───ex2_2.out
          └─ex2_2.out
third
ex2_2.out─┬─ex2_2.out─┬─ex2_2.out───ex2_2.out
          │           └─ex2_2.out
          ├─ex2_2.out───ex2_2.out
          └─ex2_2.out
fourth
ex2_2.out─┬─ex2_2.out─┬─ex2_2.out─┬─ex2_2.out───ex2_2.out
          │           │           └─ex2_2.out
          │           ├─ex2_2.out───ex2_2.out
          │           └─ex2_2.out
          ├─ex2_2.out─┬─ex2_2.out───ex2_2.out
          │           └─ex2_2.out
          ├─ex2_2.out───ex2_2.out
          └─ex2_2.out
fifth
ex2_2.out─┬─ex2_2.out─┬─ex2_2.out─┬─ex2_2.out─┬─ex2_2.out───ex2_2.out
          │           │           │           └─ex2_2.out
          │           │           ├─ex2_2.out───ex2_2.out
          │           │           └─ex2_2.out
          │           ├─ex2_2.out─┬─ex2_2.out───ex2_2.out
          │           │           └─ex2_2.out
          │           ├─ex2_2.out───ex2_2.out
          │           └─ex2_2.out
          ├─ex2_2.out─┬─ex2_2.out─┬─ex2_2.out───ex2_2.out
          │           │           └─ex2_2.out
          │           ├─ex2_2.out───ex2_2.out
          │           └─ex2_2.out
          ├─ex2_2.out─┬─ex2_2.out───ex2_2.out
          │           └─ex2_2.out
          ├─ex2_2.out───ex2_2.out
          └─ex2_2.out

Each for iteration creates a copy for each already running process, so after the first iteration there are 2 processes running, after second - 4,
after third - 8, after fourth - 16, after fifth - 32
*/