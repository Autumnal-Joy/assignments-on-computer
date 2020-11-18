#include <stdio.h>
#include <string.h>
#include "../code/create.h"
#include "../code/queue.h"
#include "../code/tree.h"
#include "../code/main.h"

int main(int argc, char const* argv[]) {
    FILE* fp = fopen("test/test.in","r");
    char pre[15];
    char mid[15];
    while(1){
        fscanf(fp,"%s %s",pre,mid);
        if(strcmp(pre,"end")==0)
            break;
        node* tree = create(pre, mid);
        postorder(tree);
        printf("\n");
        levelorder(tree);
        printf("\n");
        char target = 'D';
        if (search(tree, target)) {
            path(tree, target);
            printf("\n");
        } else {
            printf("unexisted\n");
        }
    }
    return 0;
}