#include <stdio.h>
#include "all.h" 
extern int sum;
void init(){
	sum = 0;
}

void solve(int n){
	int queen[n];
	for(int i=0;i<n;i++)
		queen[i]=-1;
	init();
	find(0,queen,n);
}
