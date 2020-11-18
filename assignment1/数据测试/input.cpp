#include <stdio.h>
#include <string.h>
void getUserInput(char* pstr) {
    scanf("%100[^=]", pstr);
    while (getchar() != '\n')
        continue;
}
