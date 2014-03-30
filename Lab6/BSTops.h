#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

BST createEmptyBST();
// BST insertBST(BST bt, book b);
int findBST(BST bt, book b); //returns true or false: 0 for found
BST deleteBST(BST bt, book b); // handle all cases of deletion

book findMaxPrice(BST bt); //in-order traversal
book findMinPrice(BST bt);//pre-order traversal
book findLatest(BST bt); //return book with max accession number
book findOldest(BST bt); //return book with min accession number
int getHeight(BST bt);
BST reOrderBST(BST bt); //in order traversal, return new price based BST

BST re2OrderBST(BST bt);

// BST createEmptyBST(){
//     // Create the root node, the first node with data
//     node root=(node)malloc(sizeof(bNode));
//     root->left = NULL;
//     root->right = NULL;
//     root = NULL;

//     // create the bst node, which points to root node of the tree
//     BST bt;
//     bt=(BST)malloc(sizeof(BinTree));
//     totalBooks=0;
//     height=0;
//     root=root;
//     return bt;
//     }
