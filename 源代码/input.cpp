#include <stdio.h>
#include <string.h>
void getUserInput(char* pstr) {
    *pstr = '\0';
    scanf("%100[^=]", pstr);
    while (getchar() != '\n')
        continue;
}
