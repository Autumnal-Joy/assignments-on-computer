#include <stdio.h>
#include "all.h"

void print_ans(int *queen, int i)
{
	int line, list;
	for (line = 0; line < i; line++)
	{
		printf("%d ", queen[line]);
	}
	printf("\n");
}
