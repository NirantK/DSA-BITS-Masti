#include "offense.h"

driver populateDrivers(FILE *source){
	driver head = (driver)malloc(sizeof(drvr));
	head->next = NULL;
	// Check if source exists	
	if(source==NULL){
	printf("Input file not found. Exiting.");
	exit(1);
	}

	// Read file into a linked list
	int uid, license;
	char c;
	// fscanf(source, "%d%c%d\n", &uid,&c,&license);
	// head ->uid = uid;
	// head ->lic = license;
	while(fscanf(source, "%d%c%d\n", &uid,&c,&license)!=EOF){
		// Create a new node and store data in it
		driver newNode =(driver)malloc(sizeof(drvr));
		newNode->uid = uid;
		newNode->lic = license;
		newNode->penalty = 0;

		// Find the first node larger than the newNode
		drvr *ptr = head;
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