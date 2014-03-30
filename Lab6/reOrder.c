#include "BSTdef.h"
#include "BSTOps.h"
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