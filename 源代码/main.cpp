#include <stdio.h>
#include "all.h"

int sum;

int main(void) {
	int n=0;
	printf("������ʺ����:");
	scanf("%d",&n);
	solve(n);
	printf("%d",sum);
	return 0;
}
