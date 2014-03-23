#include "BSTdef.h"
#include "BSTops.h"

node createNode(book *b){
    node newNode = (node)malloc(sizeof(bNode));
    newNode->b = b;
    newNode->left = newNode->right = NULL;
    return newNode;
}

node insertInBST(node tree, book *newb){
    if(tree==NULL){
        tree = createNode(newb);
        tree->left = tree->right = NULL;
    }
    else if(tree->b->acc > newb->acc){
        tree->right = insertInBST(tree->right, newb);
    }
    else
        tree->left = insertInBST(tree->left, newb);

    return tree;
}

void treePrint(node p){
    if(p!=NULL){
        treePrint(p->left);
        printf("%3d -> ", p->b->acc);
        treePrint(p->right);
    }
}

int findBST(node p, book *f){
    if(p==NULL)
        return FALSE;
    else if (p->b->acc == f->acc)
        return TRUE;
    else if(p->b->acc > f->acc)
        findBST(p->right, f);
    else
        findBST(p->left, f);
    return FALSE;
}

node searchNode(node p, book *f){
    if(p==NULL)
        return p;
    else if(p->b->acc == f->acc)
        return p;
    else if(p->b->acc > f->acc)
        searchNode(p->right, f);
    else
        searchNode(p->left, f);
}

node deleteNode(node p, book *b){

    if(findBST(p, b)==0){
        printf("The node to be deleted is not in tree.\n");
        return p;
    }
    
    node q = p;
    node x, parent, xsucc;
    while ( q != NULL ){
        /* if the node to be deleted is found */
        if ( q->b->acc == b->acc ){
            x = q ;
        }
        parent = q ;
        if (q->b->acc > b->acc)
            q = q -> right ;
        else
            q = q -> left ;
    }

    /* if the node to be deleted has two children */
    if(x->left!=NULL && x->right!=NULL){
        parent = x;
        xsucc = x->right;

        while ( xsucc -> left != NULL )
        {
            parent = xsucc ;
            xsucc = xsucc -> left;
        }
        x->b = xsucc ->b;
        x = xsucc;
    }

    /* if the node to be deleted has no child */
    if ( x -> left == NULL && x -> right == NULL )
    {
        if ( parent -> right == x )
            parent -> right = NULL ;
        else
            parent -> left = NULL ;

        free ( x ) ;
        return p;
    }

    /* if the node to be deleted has only right */
    if ( x -> left == NULL && x -> right != NULL )
    {
        if ( parent -> left == x )
            parent -> left = x -> right ;
        else
            parent -> right = x -> right ;

        free ( x ) ;
        return p;
    }

    /* if the node to be deleted has only left child */
    if ( x -> left != NULL && x -> right == NULL )
    {
        if ( parent -> left == x )
            parent -> left = x -> left ;
        else
            parent -> right = x -> left ;

        free ( x ) ;
        return p;
    }

}

int main(){
    book b = {10, "I2A", "Cormen", 720};
    book b1 = {5, "AA", "KM", 0};    
    book b2 = {7, "A2A", "K2M", 360};
    book b3 = {50, "CP", "DR", 200};
    book b4 = {100, "SM", "RK", 210};

    // node tree1 = NULL;
    // node binT = insertInBST(tree1, &b1);
    // binT = insertInBST(binT, &b1);
    // binT = insertInBST(binT, &b2);
    // binT = insertInBST(binT, &b3);    
    // binT = insertInBST(binT, &b4);
    // treePrint(binT);

    printf("\n");
    node tree2 = NULL;
    node binT2 = insertInBST(tree2, &b4);
    binT2 = insertInBST(binT2, &b3);
    binT2 = insertInBST(binT2, &b4);
    binT2 = insertInBST(binT2, &b1);    
    // insertInBST(binT2, &b);
    treePrint(binT2);
    binT2 = deleteNode(binT2, &b4);
    treePrint(binT2);

    // printf("\nTest for not found case, should return 0 for not found, returned: %d \n",findBST(binT2, &b));
    // printf("Test for found case, should return 1 for  found, returned: %d \n",findBST(binT, &b1));

    return 0;
}