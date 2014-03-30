#include "BSTdef.h"
#include "BSTOps.h"
book newb;
book findMaxP(node p){
	if(p!=NULL){
	findMaxP(p->left);
        //Operations
        // printf("Present max price: %d\n",newb.price);
        if(p->b.price>newb.price){
        	// printf(" Pointer price: %d\n",p->b.price);
        	newb = p->b;
        	// printf(" New max price: %d\n",newb.price);
        }
        findMaxP(p->right);
	}
	return newb;
}
book findMaxPrice(BST bt){
	return findMaxP(bt->root);
}

book findMinP(node p){
        if(p!=NULL){
                // Visit Node
                if(p->b.price<newb.price){
                newb = p->b;
                }
                findMinP(p->left);
                findMinP(p->right);
        }
        return newb;
}

book findMinPrice(BST bt){
        return findMinP(bt->root);
}

int findHeight(node p){
    if(p == NULL)
        return -1;

    int lefth = findHeight(p->left);
    int righth = findHeight(p->right);

    if(lefth > righth)
        return lefth + 1;
    else
        return righth +1;
}

int getHeight(BST bt){
        return findHeight(bt->root);
}

book findMaxA(node p){
        if(p!=NULL){
        findMaxA(p->left);
        //Visit Node
        if(p->b.acc>newb.acc){
                newb = p->b;
        }
        findMaxA(p->right);
        }
        return newb;
}

book findLatestBook(BST bt){
        return findMaxA(bt->root);
}

book findMinA(node p){
        if(p!=NULL){
                // Visit Node
                if(p->b.acc<newb.acc){
                newb = p->b;
                }
                findMinA(p->left);
                findMinA(p->right);
        }
        return newb;
}

book findOldestBook(BST bt){
        return findMinA(bt->root);
}