#include "BSTdef.h"
#include "BSTOps.h"

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