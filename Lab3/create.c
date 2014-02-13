#include "common.h"

void create(contact *list, FILE *source)
{	
	if(source==NULL){
	printf("Input file not found. Exiting.");
	exit(1);
	}
	char parsedLine[50];
	while(fgets(parsedLine,120,source)!=NULL){
		list->next=(contact*)malloc(sizeof(contact));
		const char s[2] = ",";
		//char *token;
		char *name = strtok(parsedLine,s);
		strcpy(list->name, name);
		printf("%s is the name I got",list->name);
		char *no = strtok(NULL,s);
		strcpy(list->num, no);
		printf("\n%s is the integer I got", list->num);
		list=list->next;
		list->next=NULL;
	//	printf("\n");
	}

}
