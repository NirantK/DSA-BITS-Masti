#include <stdio.h>
#include <stdlib.h>

typedef struct avlnode *node;

struct avlnode
{
    int key;
    struct node *left;
    struct node *right;
    int height;
};

