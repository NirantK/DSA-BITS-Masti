#include "BSTdef.h"
#include "BSTops.h"

node createNode(book *b){
    node newNode = (node)malloc(sizeof(bNode));
    newNode->b = b;
    newNode->left = newNode->right = NULL;
    return newNode;
}

book* searchBook(node p, int acc){
    // book b = {0, "", "", 0};
    if(p==NULL)
        return NULL;
    else if(p->b->acc == acc)
        return p->b;
    else if(p->b->acc < acc)
        searchBook(p->right, acc);
    else
        searchBook(p->left, acc);
}

book* findMaxPricedBook(node p){
    /*This function is not inorder traversal per se, its Morris traversal.
    It is variant of iterative inorder traversal which does not use stack. 
    You could implement this function more easily using recursion. I chose to implement this as an intellectual challenge.
    You can read about Morris traversal implementation
    at http://www.geeksforgeeks.org/inorder-tree-traversal-without-recursion-and-without-stack/
    I have used the code from above URL verbatim. 
    and thoery at http://en.wikipedia.org/wiki/Tree_traversal#Morris_in-order_traversal_using_threading

    I did not understand the utility of threading, please ping me if you do, I will be happy to call and learn from you.
    */

    int max=0, acc;
    node pre;
    node current=p;
    while(current!=NULL){
        if(current->left==NULL){
            if(current->b->price > max){
                max = current->b->price;
                acc = current->b->acc;
            }
            current = current->right;
        }
        else{
            pre = current->left;
            while(pre->right != NULL && pre->right != current)
                pre = pre->right;

              /* Make current as right child of its inorder predecessor */
            if(pre->right == NULL){
                pre->right = current;
                current = current->left;
            }
                     
            /* Revert the changes made in if part to restore the original 
                tree i.e., fix the right child of predecssor */   
            else{
                pre->right = NULL;
                if(current->b->price > max){
                    max = current->b->price;
                    acc = current->b->acc;
                }
                current = current->right;      
              }
        }
    }
    book *x = searchBook(p, acc);
    return x;
}

node insertInBST(node tree, book newb){
    if(tree==NULL){
        tree = createNode(newb);
        tree->left = tree->right = NULL;
    }
    else if(tree->b->acc < newb->acc){
        tree->right = insertInBST(tree->right, newb);
    }
    else
        tree->left = insertInBST(tree->left, newb);

    return tree;
}

void treePrint(node p){
    if(p!=NULL){
        treePrint(p->left);
        printf("%3d->", p->b->acc);
        treePrint(p->right);
    }
}

int findNode(node p, book *f){
    if(p==NULL){
        return FALSE;
    }
    if (p->b->acc == f->acc)
        return TRUE;
    else if(p->b->acc < f->acc){
        findNode(p->right, f);}
    else{
        // printf("\n%d\t%d",p->b->acc, f->acc);
        findNode(p->left, f);
    }
}

node searchNode(node p, book *f){
    if(p==NULL)
        return p;
    else if(p->b->acc == f->acc)
        return p;
    else if(p->b->acc < f->acc)
        searchNode(p->right, f);
    else
        searchNode(p->left, f);
}


void deleteNode(node p, book *b){

    if(findNode(p, b)==0){
        printf("The node to be deleted is not in tree.\n");
        return;
    }

    node q = p;
    node x, parent, xsucc;

    while(q->b->acc != b->acc && q!=NULL){
        if(q->b->acc > b->acc){
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

int main(){
    book b = {10, "I2A", "Cormen", 720};
    book b1 = {5, "AA", "KM", 0};    
    book b2 = {7, "A2A", "K2M", 360};
    book b3 = {50, "CP", "DR", 200};
    book b4 = {100, "SM", "RK", 210};
    book b5 = {9, "SM", "RK", 210};
    book b6 = {90, "SM", "RK", 210};

    node tree1 = NULL;
    node binT = insertInBST(tree1, &b);
    binT = insertInBST(binT, &b1);
    binT = insertInBST(binT, &b2);
    binT = insertInBST(binT, &b3);    
    binT = insertInBST(binT, &b4);
    
    // printf("tree1:\n");
    // treePrint(binT);

    printf("\n");
    
    node tree2 = NULL;
    node binT2 = insertInBST(tree2, &b);
    binT2 = insertInBST(binT2, &b1);
    binT2 = insertInBST(binT2, &b2);
    binT2 = insertInBST(binT2, &b3);    
    binT2 = insertInBST(binT2, &b4);
    // binT2 = insertInBST(binT2, &b5);
    // binT2 = insertInBST(binT2, &b6);
    printf("\nbeforedel\ttree2:\n");
    book* maxPrice = findMaxPricedBook(binT2);
    printf("%s written by %s has maximum price, which is %d \n",maxPrice->title, maxPrice->name, maxPrice->price);
    treePrint(binT2);
    deleteNode(binT2, &b2);    
    deleteNode(binT2, &b3); 
    printf("\nafterdel\ttree2:\n");
    treePrint(binT2);
    printf("\n");
    
    printf("\nTest for not found case, should return 0 for not found, returned: %d \n",findNode(binT2, &b4));
    printf("Test for found case, should return 1 for  found, returned: %d \n",findNode(binT2, &b1));
    // node x = searchNode(binT2, &b);
    // printf("Search Node b: %d, %s, %s, %d\n", x->b->acc, x->b->title, x->b->name, x->b->price);

    return 0;
}