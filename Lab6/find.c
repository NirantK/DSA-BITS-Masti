#include "BSTdef.h"
#include "BSTOps.h"
int findNode(node p, book f){
    if(p==NULL){
        return FALSE;
    }
    else if (p->b.acc == f.acc){
        return TRUE;
    }
    else if(p->b.acc < f.acc){
        findNode(p->right, f);}
    else{
        findNode(p->left, f);
    }
}
int findBST(BST bt, book b){
	return findNode(bt->root, b);
}