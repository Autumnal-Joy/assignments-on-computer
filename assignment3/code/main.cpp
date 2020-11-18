#include "main.h"
#include <stdio.h>
#include "create.h"
#include "tree.h"

int main(int argc, char const* argv[]) {
    FILE* src = stdin;
    src = fopen("input", "r");
    char pre[10000];
    char mid[10000];
    fscanf(src, "%10000s %10000s", pre, mid);
    node* tree = create(pre, mid);
    postorder(tree);
    printf("\n");
    levelorder(tree);
    printf("\n");
    char target = 'M';
    if (search(tree, target)) {
        path(tree, target);
    } else {
        printf("unexisted");
    }
    return 0;
}
