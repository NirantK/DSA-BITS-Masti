#include "offense.h"

int main()
{	
	// int a = 9253298;
	// printf("%d\n", a);
	FILE *ownerSource = fopen("owners.txt", "r");
	ownr *olist = (ownr*)malloc(sizeof(ownr));
	populateVehicles(olist, ownerSource);
	FILE *driverSource = fopen("drivers.txt", "r");
	drvr *list = (drvr*)malloc(sizeof(drvr));
	populateDrivers(list, driverSource);
	return 0;
}

void populateVehicles(ownr *list, FILE *source){
	int i;

	// Check if source exists
	if(source==NULL){
	printf("Input file not found. Exiting.");
	for(i=99999999;i>0;i--);
	exit(1);
	}

	printf("Unsorted populateVehicles\n");
	// Read file into a linked list
	int uid, vehno;
	// while(fgets(parsedLine,15,source)!=NULL)
	while(fscanf(source, "%d,%d", &uid,&vehno)!=EOF){
		list->next=(ownr*)malloc(sizeof(ownr));
		list->uid = uid;
		list->vno = vehno;
		printf("%d,%d", list->uid, list->vno);
		printf("\n");
	}
	printf("--------------------------------------------------\n");
}

void populateDrivers(drvr *list, FILE *source){
	int i;

	// Check if source exists
	if(source==NULL){
	printf("Input file not found. Exiting.");
	for(i=99999999;i>0;i--);
	exit(1);
	}

	// Read file into a linked list
	int uid, license;
	// while(fgets(parsedLine,15,source)!=NULL)
	while(fscanf(source, "%d,%d", &uid,&license)!=EOF){
		list->next=(drvr*)malloc(sizeof(drvr));
		list->uid = uid;
		list->lic = license;
		printf("%d,%d", list->uid, list->lic);
		printf("\n");
	}
}