#include <stdio.h>
void getUserInput(char* pstr) {  //¶ÁÈë×Ö·û´®
    scanf("%100[^=]", pstr);
    while (getchar() != '\n')
        continue;
}
void preProcess(char* pstr) {  // Ô¤´¦Àí×Ö·û´®
    int i = 0;
    if (pstr[0] == '-')
        pstr[0] = '~';
    while (pstr[++i]) {
        if (pstr[i] == '-') {
            if (pstr[i - 1] == '(')
                pstr[i] = '~';
        }
    }
}
int main(void) {
	fclose(fopen("./a.out", "w"));
    char pstr[100];
    while (1) {
        FILE* output = fopen("./a.out", "a+");
        getUserInput(pstr);
        preProcess(pstr);
        fprintf(output, "%s\n", pstr);
        fclose(output);
    }
}
