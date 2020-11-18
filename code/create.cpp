#include <stdlib.h>
#include <string.h>
#include "tree.h"

static char* str;
static int i;

node* help(char mid[], int start, int end) {
    if (start >= end) {
        return NULL;
    }
    node* tree = (node*)malloc(sizeof(node));
    char* p = strchr(mid, str[i++]);
    int index = p - mid;
    tree->data = mid[index];
    tree->left_child = help(mid, start, index);
    tree->right_child = help(mid, index + 1, end);
    return tree;
}
node* create(char pre[], char in[]) {
    str = pre;
    i = 0;
    return help(in, 0, strlen(in));
}