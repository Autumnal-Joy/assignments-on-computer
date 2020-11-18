#include <stdio.h>
#include <string.h>
#include "../code/create.h"
#include "../code/queue.h"
#include "../code/tree.h"
#include "../code/main.h"
int main(int argc, char const *argv[])
{
    FILE* fp = fopen("test/test.in","r");
    char pre[15];
    char mid[15];
    node* t;
    node* ad;
    while(1){
        fscanf(fp,"%s %s",pre,mid);
        if(strcmp(pre,"end")==0){
            break;
        }
        t = create(pre,mid);
    }
    return 0;
}