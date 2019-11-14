#include <stdio.h>

#define PROCESS_NUM 5
#define RESOURCE_NUM 3

int main()
{
	int e[RESOURCE_NUM];
	int a[RESOURCE_NUM];
	int c[PROCESS_NUM][RESOURCE_NUM];
	int r[PROCESS_NUM][RESOURCE_NUM];
	int mark[PROCESS_NUM];

	int deadlocked = 0;

	//reading from file
	FILE *in = fopen("input.txt", "r");
	for (int i = 0; i < RESOURCE_NUM; i++)
	{
		fscanf(in, "%d", &(e[i]));
	}
	for (int i = 0; i < RESOURCE_NUM; i++)
	{
		fscanf(in, "%d", &(a[i]));
	}
	for (int i = 0; i < PROCESS_NUM; i++)
	{
		for (int j = 0; j < RESOURCE_NUM; j++)
		{
			fscanf(in, "%d", &(c[i][j]));
		}
	}
	
	for (int i = 0; i < PROCESS_NUM; i++)
	{
		mark[i] = 0;
	}

	for (int i = 0; i < PROCESS_NUM; i++)
	{
		for (int j = 0; j < RESOURCE_NUM; j++)
		{
			fscanf(in, "%d", &(r[i][j]));
		}
	}

	//implementing the algorithm itself
	for (int i = 0; i < PROCESS_NUM; i++)
	{
		int found = 0;
		for (int j = 0; j < PROCESS_NUM; j++)
		{
			if (mark[j] == 0)
			{
				int ok = 1;
				for (int k = 0; k < RESOURCE_NUM; k++)
				{
					if (a[k] < r[j][k])
					{
						ok = 0;
					}
				}
				if (ok)
				{
					found = 1;
					for (int k = 0; k < RESOURCE_NUM; k++)
					{
						a[k] += c[j][k];
					}
					mark[j] = 1;
					break;
				}
			}
		}
	}

	for (int i = 0; i < PROCESS_NUM; i++)
	{
		if (mark[i] == 0)
		{
			mark[i] = 1;
			for (int j = 0; j < RESOURCE_NUM; j++)
			{
				if (c[i][j] < r[i][j])
				{
					mark[i] = 0;
					deadlocked = 1;
				}
			}
		}
	}

	//printing results
	FILE *out;
	if (deadlocked)
	{
		out = fopen("output_dl.txt", "w");
		fprintf(out, "deadlocked processes: ");
		for (int i = 0; i < PROCESS_NUM; i++)
		{
			if (mark[i] == 0)
			{
				fprintf(out, "%d, ", i + 1);
			}
		}
	}
	else
	{
		out = fopen("output_ok.txt", "w");
		fprintf(out, "no deadlock detected\n");
	}
	fclose(out);
	fclose(in);

	return 0;
}