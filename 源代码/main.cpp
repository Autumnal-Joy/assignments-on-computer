#include <stdio.h>
#include "all.h"

int sum;

int main(void) {
	int n=0;
	printf("请输入皇后个数:");
	scanf("%d",&n);
	solve(n);
	printf("%d",sum);
	return 0;
}
