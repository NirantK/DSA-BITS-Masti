#include "offense.h"

int main()
{	
	// int a = 9253298;
	// printf("%d\n", a);
	FILE *ownerSource = fopen("owners.txt", "r");
	owner o= populateVehicles(ownerSource);
	// printVehicleList(o);
	// printf("--------------------------------------------------\n");
	FILE *driverSource = fopen("drivers.txt", "r");
	driver d = populateDrivers(driverSource);
	// printDriversList(d);
	makeRevokeList()
	return 0;
}

void makeRevokeList(offense head, FILE *source)
{
		// Check if source exists
	if(source==NULL){
	printf("Input file not found. Exiting.");
	exit(1);
	}

	// Read file into a linked list
	int license, penalty;
	char c;
	// fscanf(source, "%d%c%d\n", &uid,&c,&license);
	// head ->uid = uid;
	// head ->lic = license;
	while(fscanf(source, "%d%c%d\n", &license,&c,&penalty)!=EOF){
		// Create a new node and store data in it
		offense newNode =(offense)malloc(sizeof(ofnc));
		newNode->lic = license;
		newNode->pen = penalty;

		// Find the first node larger than the newNode
		ofnc *ptr = head;
		while(ptr->next!=NULL && ptr->next->lic<license){
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
	printOffensesList(head);
}

