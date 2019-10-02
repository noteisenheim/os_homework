#include <stdlib.h>
#include <stdio.h>

const int a = 3;	//initialized constant global, stored in data segment
int b = 15;	//initialized global, stored in data segment
int c;	//uninitialized global, stored in bss

int main()
{
	static int d = 23;	//initialized static, stored in data segment
	static int e;	//uninitialized static, stored in bss
	int f = a + b;	//initialized local, stored in data segment
	printf("f = %d\n", f);
	return 0;
}