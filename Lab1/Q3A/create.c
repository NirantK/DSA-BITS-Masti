#include "common.h"

void create(node *list, FILE *source)
{	
	if(source==NULL){
	printf("Input file not found. Exiting.");
	exit(1);
	}
	while(fscanf(source, "%c",&list->a)!=EOF){
		list->next=(node*)malloc(sizeof(node));
		list=list->next;
		list->next=NULL;
	}	
	return;
}