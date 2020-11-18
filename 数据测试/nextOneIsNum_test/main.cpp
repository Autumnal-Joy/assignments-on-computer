#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
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
			isNum = nextOneIsNum(pstr,&nextOpe,&nextNum);
			if(isNum)
				fprintf(output,"%f",nextNum);
			else
				fprintf(output,"%c",nextOpe);
		}while(nextOpe != '=');
    	fprintf(output,"\n");
    	fclose(output);
    }
}

