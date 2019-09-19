#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>

#define N 5

void *print_thread(void *arg)
{
	sleep(1);
	printf("hello from thread #%lu\n", pthread_self());
}

void create_thread()
{
	pthread_t t_id;

	pthread_create(&t_id, NULL, print_thread, NULL);
	printf("thread created with id %lu\n", t_id);
	
	pthread_join(t_id, NULL);
	printf("thread with id %lu exited\n", t_id);
}

int main()
{
	for (int i = 0; i < N; i++)
	{
		create_thread();
	}
	return 0;
}