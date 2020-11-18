#include <stdio.h>
#include "all.h"
extern int sum;
void find(int i,int* queen,int n) {
	int cur_col;
	if(i==n) {
		sum++;
		print_ans(queen,n);
	}
	for(cur_col = 0; cur_col < n; cur_col++) {
		queen[i] = cur_col;
		if(judge(queen,i)) {
			find(i+1,queen,n);
		}
		queen[i] = -1;
	}
}
