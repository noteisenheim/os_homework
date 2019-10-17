/*
	assume that page numbering starts with 1
	each page reference happen with the interval of one clock tick
*/

#include <stdio.h>
#include <time.h>
#include <limits.h>

#define FRAMES 100

FILE *file;

int pages[FRAMES];
int R[FRAMES];
unsigned int counters[FRAMES];
int hit = 0;
int miss = 0;
char temp;

//reads the next references page number
int get_page() 
{
	if ((temp == EOF) || (temp == '\n'))
	{
		return -1;
	}

	char t[3];
	int c = 0;

	temp = fgetc(file);

	while (temp != EOF) 
	{
		if(temp != ' ')
		{
			if (temp != '\n')
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

//checks whether referenced page is stored in memory
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

//shifts counters and adds the R bit
void update_counters()
{
	for (int i = 0; i < FRAMES; i++)
	{
		counters[i] = counters[i] >> 1;
		if (R[i] == 1)
		{
			counters[i] += 32768;
		}
	}
}

//finds the index of the entry with the least counter value
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

int main() 
{

	file = fopen("input.txt", "r");
	if (file == NULL)
	{
		printf("couldn't open file\n");
		return 0;
	}

	while (1)
	{
		int page = get_page();

		if (page != -1)
		{
			int index = is_in_table(page);
			//if referenced page is not stored in memory
			if (index != -1)
			{
				hit++;
				R[index] = 1;
				update_counters();
				R[index] = 0;
			}
			//otherwise
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

	printf("hits = %d\nmiss = %d\nhit/miss ratio = %f", hit, miss, (float)hit / (float)miss);

	return 0;
}

/*
	for 10 page frames: 
		hits = 25
		miss = 975
		hit/miss ratio = 0.025641

	for 50 page frames:
		hits = answer to the ultimate question of life, the universe, and everything
		miss = 958
		hit/miss ratio = 0.043841

	for 100 page frames:
		hits = answer to the ultimate question of life, the universe, and everything
		miss = 958
		hit/miss ratio = 0.043841
*/