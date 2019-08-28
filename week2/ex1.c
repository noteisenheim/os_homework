#include <stdio.h>
#include <limits.h>
#include <float.h>

int main()
{
	int a;
	float b;
	double c;
	a = INT_MAX;
	b = FLT_MAX;
	c = DBL_MAX;

	printf("a = %d, size of a = %ld\n", a, sizeof(a));
	printf("b = %E, size of b = %ld\n", b, sizeof(b));
	printf("c = %E, size of c = %ld\n", c, sizeof(c));
	return 0;
}