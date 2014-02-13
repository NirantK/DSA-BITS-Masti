#include "common.h"
void print(contact *list){
	//contact *head = contact *list;
	while(list->next!=NULL)
	{
		printf("%s|%s",list->name,list->num);
		if(list->next->next==NULL){return;}
		//print(list->next);
		list = list->next;
	}
	printf("\n");
	return;
}
