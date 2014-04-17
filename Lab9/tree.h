#include <stdio.h>
#include <stdlib.h>

typedef struct avlnode *PurchaseData;

struct avlnode
{
    int custId;
    int itemId;
    struct node *left;
    struct node *right;
    int height;
};