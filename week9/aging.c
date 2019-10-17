/*
	assume that page numbering starts with 1
	each page reference happen with the interval of one clock tick
*/

#include <stdio.h>
#include <time.h>
#include <limits.h>

#define FRAMES 10

FILE *file;
file = fopen("input.txt", "r");

int pages[FRAMES];
int R[FRAMES];
int counters[FRAMES];
int hit = 0;
int miss = 0;

int get_page() 
{
	char t[3];
	char temp;
	int c = 0;

	temp = fgetc(file);
	if (temp == EOF)
	{
		return -1;
	}

	while (temp != EOF) 
	{
		if(temp != " ")
		{
			t[c] = temp;
			c++;
			temp = fgetc(file);
		}
		else 
		{
			break;
		}
	}
	int num = 0;
	int dec = 1;
	for (int i = 0; i < c; i++)
	{
		num += dec * (t[2 - i] - '0');
		dec = dec * 10;
	}

	return num;
}

int is_in_table(int page) 
{
	int found = 0;
	for (int i = 0; i < FRAMES; i++)
	{
		if (pages[i] == page)
		{
			found = 1;
			return i;
		}
	}

	return -1;
}

void update_counters()
{
	for (int i = 0; i < FRAMES; i++)
	{
		counters[i] = counters[i] >> 1;
		if (R[i] == 1)
		{
			counters[i] |= 1UL << n;
		}
	}
}

int find_min_counter()
{
	int min = counters[0];
	int ind = 0;
	for (int i = 1; i < FRAMES; i++)
	{
		if (counters[i] < min)
		{
			min = counters[i];
			ind = i;
		}
	}

	return ind;
}

int main() {

	while (true)
	{
		int page = get_page();
		if (page != -1)
		{
			int index = is_in_table(page);
			if (index != -1)
			{
				hit++;
				R[i] = 1;
				update_counters();
				R[i] = 0;
			}
			else
			{
				miss++;
				int insert_ind = find_min_counter();
				pages[insert_ind] = page;
				counters[insert_ind] = 0;
				R[insert_ind] = 1;
				update_counters();
				R[insert_ind] = 0;
			}
		}
		else
		{
			break;
		}
	}

	printf("hits = %d\nmiss = %d\nhit/miss ratio = %f", hits, miss, (float)hits / (float)miss);

	return 0;
}