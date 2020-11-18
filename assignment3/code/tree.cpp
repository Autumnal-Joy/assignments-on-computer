#include <stdio.h>
#include <stdlib.h>
#include "main.h"
#include "queue.h"

void postorder(node *ptr)
{
    if (!ptr)
    {
        return;
    }
    postorder(ptr->left_child);
    postorder(ptr->right_child);
    printf("%c", ptr->data);
}

void levelorder(node *ptr)
{
    if (!ptr)
    {
        return;
    }
    queue s;
    initqueue(s);
    enqueue(s, ptr);
    while (s.front)
    {
        node *tree = dequeue(s);
        if (tree->left_child)
        {
            enqueue(s, tree->left_child);
        }
        if (tree->right_child)
        {
            enqueue(s, tree->right_child);
        }
        printf("%c", tree->data);
    }
}

node *search(node *ptr, char c)
{
    if (!ptr)
    {
        return NULL;
    }
    if (ptr->data == c)
    {
        return ptr;
    }
    node *left = search(ptr->left_child, c);
    if (left)
    {
        return left;
    }
    node *right = search(ptr->right_child, c);
    return right;
}

void path(node *root, char c)
{
    if (!root)
    {
        return;
    }
    if (search(root->left_child, c))
    {
        printf("%c", root->data);
        path(root->left_child, c);
    }
    else if (search(root->right_child, c))
    {
        printf("%c", root->data);
        path(root->right_child, c);
    }
    else
    {
        printf("%c", root->data);
        return;
    }
}