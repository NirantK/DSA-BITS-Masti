#include<stdio.h>
#include<stdlib.h>
 
// An AVL tree node
struct node
{
    int custId;
    int itemId;//dta
    struct node *left;
    struct node *right;//pointers
    int height;
};

typedef struct node *purchaseInfo;

struct AVLRootNode{
	purchaseInfo root;
};

typedef struct AVLRootNode *PurchaseData;
