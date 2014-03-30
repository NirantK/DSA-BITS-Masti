#include "BSTdef.h"
#include "BSTOps.h"
void deleteNode(node p, book b){

    if(findNode(p, b)==0){
        printf("The node to be deleted is not in tree.\n");
        return;
    }

    node q = p;
    node x, parent, xsucc;

    while(q->b.acc != b.acc && q!=NULL){
        if(q->b.acc > b.acc){
            parent = q;
            q = q->left;
        }
        else{
            parent = q;
            q = q->right;
        }
    }
    x=q;

    /* if the node to be deleted has two children */ 
    if(x->left!=NULL && x->right!=NULL){
        parent = x;
        xsucc = x->right;

        while (xsucc->left != NULL)
        {
            parent = xsucc ;
            xsucc = xsucc->left;
        }
        x->b = xsucc ->b;
        x = xsucc;
    }

    // /* if the node to be deleted has no child */
    if (x->left == NULL && x->right == NULL){
        if (parent->right == x)
            parent->right = NULL ;
        else
            parent->left = NULL ;
        free (x) ;
        return;
    }

    /* if the node to be deleted has only right */
    if (x->left == NULL && x->right != NULL)
    {
        if (parent->left == x)
            parent->left = x->right ;
        else
            parent->right = x->right ;

        free (x) ;
        return;
    }

    /* if the node to be deleted has only left child */
    if (x->left != NULL && x->right == NULL)
    {
        if (parent->left == x)
            parent->left = x->left ;
        else
            parent->right = x->left ;

        free (x) ;
        return; 
    }
}

BST delBST(BST bt, book b){
	deleteNode(bt->root, b);
	return bt;
}