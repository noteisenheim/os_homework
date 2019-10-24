#include <stdio.h>
#include <dirent.h>
#include <string.h>
#include <stdlib.h>

int main()
{
	int inodes[10];
	char *names[10];
	int count = 0;
	DIR *dir = opendir("./temp");	//opening directory
	if (dir == NULL)
	{
		printf("such directory doesn't exist\n");
	}
	else	//if directory exists
	{
		struct dirent *dp;
		//reading all files and their inodes, saving them
		while ((dp = readdir(dir)) != NULL)
		{
			inodes[count] = dp->d_ino;
			names[count] = calloc(strlen(dp->d_name), sizeof(char));
			names[count] = dp->d_name;
			count++;
		}
	}
	//searching for the repeating inodes and printing if they exist
	for (int i = 0; i < count; i++)
	{
		int found = 0;
		for (int j = i + 1; j < count; j++)
		{
			if (inodes[i] == inodes[j])
			{
				found = 1;
				printf("%s ", names[j]);
			}
		}
		if (found)
		{
			printf("%s: %d\n", names[i], inodes[i]);
		}
	}
	return 0;
}