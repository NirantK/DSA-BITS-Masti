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