#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

int main()
{
	void *p = NULL;
	for(int i = 0; i < 10; i++)
	{
		p = calloc(1, 1024 * 1024 * 500);	//allocating 500Mb memory
		memset(p, 0, 1024 * 1024 * 500);
		sleep(1);
	}
	return 0;
}

/*
	on my laptop nothing happens, it does not use swap area at all, so nothing is swapped in or out
	when i increase the size of allocated memory, the swap area is used
*/

/*
	ex3:
	the program gradually moves to the top as it takes more and more memory
*/