#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>

#define MAX_NUM 10

int buffer = 0;
int empty = 1;
int full = 0;

void *produce(void *args)
{
	while (1)
	{
		if (full)
		{
			continue;
		}
		buffer = buffer + 1;
		empty = 0;

		if (buffer == MAX_NUM)
		{
			full = 1;
		}
	}
}

void *consume(void *args)
{
	while (1)
	{
		if (empty)
		{
			continue;
		}
		buffer = buffer - 1;
		full = 0;

		if (buffer == 0)
		{
			empty = 1;
		}
	}
}

void *print(void *args)
{
	while (1)
	{
		FILE *fp;
		fp = fopen("ex3.txt", "a");
		fprintf(fp, "buffer is %d\n", buffer);
		fprintf(fp, "full is %d\n", full);
		fprintf(fp, "empty is %d\n", empty);
		fclose(fp);
		sleep(60);
	}
}

int main()
{
	pthread_t producer, consumer, printer;

	pthread_create(&producer, NULL, produce, NULL);
	pthread_create(&consumer, NULL, consume, NULL);
	pthread_create(&printer, NULL, print, NULL);

	pthread_join(producer, NULL);
	pthread_join(consumer, NULL);
	pthread_join(printer, NULL);

	return 0;
}

/*
the race condition occured on the 2nd minute: producer and consumer both are in waiting state
the full flag is set to 1 and the empty flag is set to 1 so they both are busy waiting
*/