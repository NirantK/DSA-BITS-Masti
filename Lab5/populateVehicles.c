#include "offense.h"
owner populateVehicles(FILE *source){
	// Check if source exists
	if(source==NULL){
	printf("Input file not found. Exiting.");
	exit(1);
	}

	owner head = (owner)malloc(sizeof(ownr));

	// int used = 0 ; //number of tuples read

	// Read file into a linked list
	int uid, vehno;
	char c;
	while(fscanf(source, "%d%c%d\n", &uid,&c,&vehno)!=EOF){
		// Create a new node and store data in it
		owner newNode =(owner)malloc(sizeof(ownr));
		newNode->uid = uid;
		newNode->vno = vehno;

		// Find the first node larger than the newNode
		owner ptr = head;
		while(ptr->next!=NULL && ptr->next->uid<uid){
			ptr = ptr->next;
		}
		if (ptr->next==NULL){
			newNode->next = NULL;
			// printf("poop\n");
			ptr->next = newNode;				
		}
		else{
			newNode->next = ptr->next;
			ptr->next = newNode;
		}
	}
	return head;
}