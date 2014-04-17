#include<stdio.h>
#include<stdlib.h>
 
// An AVL tree node
struct node
{
    int custId;
    int itemId;
    struct node *left;
    struct node *right;
    int height;
};

typedef struct node *purchaseInfo;

struct AVLRootNode{
	purchaseInfo root;
};

typedef struct AVLRootNode *PurchaseData;
