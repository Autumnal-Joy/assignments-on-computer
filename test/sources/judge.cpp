#include <stdio.h>
#include <stdlib.h>
#include "all.h"

int judge(int* queen,int cur_col) {
	for(int j=0; j<cur_col; j++) {
		if(abs(queen[j]-queen[cur_col])==abs(j-cur_col) || queen[j]==queen[cur_col])
			return 0;
	}
	return 1;
}
