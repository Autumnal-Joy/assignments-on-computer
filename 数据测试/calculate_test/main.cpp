#include <stdio.h>
#include <ctype.h>
#include <math.h>
#include <stdlib.h>
#include "all.h"

int main(void) {
    fclose(fopen("./a.out", "w"));
    char pstr[100];
    while (1) {
    	FILE* output = fopen("./a.out", "a");
        getUserInput(pstr);
        double res;
	    res = calculate(pstr);
	    fprintf(output,"%g\n",res);
    	fclose(output);
    }
}
