#include <stdio.h>
#include <stdlib.h>
typedef struct __bookNode bNode; 
typedef struct __bookNode* node;
typedef struct __book book;
typedef struct __bst* BST;
typedef struct __bst BinTree;

struct __bst{
	int totalBooks;
	int height;
	node root;
};

struct __book{
	int acc; //unique accession number
	char *title;
	char *name;
	int price;
};

struct __bookNode
{
	book b;
	struct __bookNode *left, *right;
};

#define TRUE 1
#define FALSE 0