#include <stdio.h>
#include <stdlib.h>
struct pos{
	long pos;
	struct pos * next;
};

struct pos * newNode(long pos){
 	struct pos *newNode = (struct pos*)malloc(sizeof(struct pos));
 	newNode->pos = pos;
 	newNode->next = NULL;
 	return newNode;
 }
 struct pos * insert(struct pos* root, long pos){
 	struct pos *temp = root;
 	if(temp==NULL){
 		temp = newNode(pos);
 		return root;
 	}
 	if ( temp != NULL ) {
        while ( temp->next != NULL)
        {
            temp = temp->next;
        }
    }
    temp->next = newNode(pos);
 	return root;
}
 void print(struct pos * root){
	root = root->next;
 	while(root!=NULL){
 		printf("%ld\t", root->pos);
 		root = root->next;
 	}
 }
  int main(){
 	struct pos *root = (struct pos*)malloc(sizeof(struct pos));
 	root->next = NULL;
 	root->pos = 0;
 	// root = (struct pos*)malloc(sizeof(struct pos));
 	// root->next = NULL;
 	// root->pos = 0;
 	root = insert(root, 5);
 	root = insert(root, 15);
 	root = insert(root, 15);
 	root = insert(root, 15);
 	root = insert(root, 15);
 	root = insert(root, 55);

 	print(root);
 	return 0;
 }