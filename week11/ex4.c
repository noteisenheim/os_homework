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
	//open files
	int in_file = open("ex1.txt", O_RDONLY);
	int out_file = open("ex1.memcpy.txt", O_RDWR | O_CREAT, 0666);

	//mapping input file
	size_t in_size = lseek(in_file, 0, SEEK_END);
	char *in_map = mmap(0, in_size, PROT_READ, MAP_SHARED, in_file, 0);

	//resizing output file, mapping it
	ftruncate(out_file, in_size);
	char *out_map = mmap(0, in_size, PROT_READ | PROT_WRITE, MAP_SHARED, out_file, 0);

	//copying contene
	memcpy(out_map, in_map, in_size);

	//saving changes, unmapping memory and closing files
	int s = msync(out_map, in_size, MS_SYNC);
	munmap(in_map, in_size);
	munmap(out_map, in_size);
	close(in_file);
	close(out_file);

	return 0;
}