#include <stdio.h>
#include <dirent.h>
#include <string.h>
#include <stdlib.h>

int main()
{
	int inodes[10];
	char *names[10];
	int count = 0;
	DIR *dir = opendir("./temp");
	if (dir == NULL)
	{
		printf("such directory doesn't exist\n");
	}
	else
	{
		struct dirent *dp;
		while ((dp = readdir(dir)) != NULL)
		{
			inodes[count] = dp->d_ino;
			names[count] = calloc(strlen(dp->d_name), sizeof(char));
			names[count] = dp->d_name;
			count++;
		}
	}
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