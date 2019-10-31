#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/mman.h>
#include <string.h>

int main()
{
	//opens file
	int file = open("ex1.txt", O_RDWR, (mode_t)0600);

	if (file < 0)
	{
		printf("error while opening\n");
	}
	else
	{
		char *text = "This is a nice day";
		size_t textsize = strlen(text) + 1;
		struct stat fileinfo = {0};

		if (fstat(file, &fileinfo) < 0)
		{
			printf("error while getting the size\n");
		}
		else
		{
			//erase file content
			lseek(file, textsize-1, SEEK_SET);
			int w = write(file, "", 1);
			//map memory
			char *map = mmap(0, textsize, PROT_READ | PROT_WRITE, MAP_SHARED, file, 0);
			printf("%d\n", textsize);
			if (map == MAP_FAILED)
			{
				close(file);
				printf("error while mapping\n");
			}
			else
			{
				//write text to file
				for (size_t i = 0; i < textsize; i++)
				{
					map[i] = text[i];
				}

				//save changes, unmap, close file
				int s = msync(map, textsize, MS_SYNC);
				int m = munmap(map, textsize);
				close(file);
			}
		}

	}
	return 0;
}