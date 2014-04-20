#include "BSTdef.h"
#include "BSTOps.h"
BST createEmptyBST()
{
	node head=NULL;
	BST bt= (BST) malloc(sizeof(BinTree));
	bt->totalBooks=0;
	bt->height=0;
	bt->root=head;

	return bt;
}

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
        free(x);
        return;
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

int findBST(BST bt, book b){
	return findNode(bt->root, b);
}

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
    // else
    // 	return (findHeight(p->left)+1+findHeight(p->right));
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

node createNode(book b){
    node newNode = (node)malloc(sizeof(bNode));
    newNode->b = b;
    newNode->left = newNode->right = NULL;
    return newNode;
}

node insertInBST(node tree, book newb){
    if(tree==NULL){
        tree = createNode(newb);
        tree->left = tree->right = NULL;
    }
    else if(tree->b.acc < newb.acc){
        tree->right = insertInBST(tree->right, newb);
    }
    else
        tree->left = insertInBST(tree->left, newb);

    return tree;
}
BST insertBST(BST bt, book b){
    bt->root=insertInBST(bt->root, b);
    bt->totalBooks++;
    return bt;
}

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

node insertPrice(node tree, book newb){
	// printf("newb %s\n", newb.title);
	if(tree==NULL){
		tree = createNode(newb);
		tree->left = tree->right = NULL;
		// printf("Inserting %d with price %d\n", newb.acc, newb.price);
	}
	else if(tree->b.price < newb.price){
		tree->right = insertPrice(tree->right, newb);
		// printf("Inserting %d with price %d\n", newb.acc, newb.price);
	}
	else{
		tree->left = insertPrice(tree->left, newb);
		// printf("Inserting %d with price %d\n", newb.acc, newb.price);
	}
	return tree;
}


node reOrd(node root, node tree){
	if(root!=NULL){
		tree = reOrd(root->left, tree);
		if(tree==NULL){
			tree = createNode(root->b);
			tree->left = tree->right = NULL;
		}
		else{
			tree = insertPrice(tree, root->b);

		}
		tree = reOrd(root->right, tree);
	}
	
	return tree;
}

BST reOrderBST(BST bt){
	BST btp = createEmptyBST();
	btp->root = reOrd(bt->root, btp->root);
	return btp;
}