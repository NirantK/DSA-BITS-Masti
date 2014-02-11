#include "common.h"
void print(node *list){
	while(list->next!=NULL)
	{
		printf("%d ",list->a);
		if(list->next->next==NULL){return;}
		//print(list->next);
		list = list->next;
	}
	// printf("\n");
	return;
}