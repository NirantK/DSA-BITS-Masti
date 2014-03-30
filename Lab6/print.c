#include "BSTdef.h"
#include "BSTOps.h"
void treePrint(node p){
    if(p!=NULL){
        treePrint(p->left);
        printf("%d-> ", p->b.acc);
        treePrint(p->right);
    }
}

void bstPrint(BST bt){
	treePrint(bt->root);
}