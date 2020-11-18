#include <stdio.h>
#include "all.h"

int main(void) {
    fclose(fopen("./a.out", "w"));
    char pstr[100];
    while (1) {
    	FILE* output = fopen("./a.out", "a");
        getUserInput(pstr);
        char nextOpe,isNum;
    	double nextNum;
        do{
	        isNum = nextOneIsNum(pstr, &nextOpe,&nextNum);
	        if(!isNum){
	        	fprintf(output,"%c: %d, ",nextOpe, checkPriority(nextOpe));
			}
		}while(nextOpe != '=');
		fprintf(output,"\n");
    	fclose(output);
    }
}
