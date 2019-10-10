#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/resource.h>

int main()
{
	struct rusage usage;
	void *p = NULL;
	for(int i = 0; i < 10; i++)
	{
		p = calloc(1, 1024 * 1024 * 10);	//allocating 10Mb memory
		memset(p, 0, 1024 * 1024 * 10);
		getrusage(RUSAGE_SELF, &usage);
		printf("%ld\n", usage.ru_maxrss);
		sleep(1);
	} 
	return 0;
}

/*
	output is:
	11216
	21692
	31988
	42284
	52580
	62876
	72908
	83204
	93500
	103796

*/