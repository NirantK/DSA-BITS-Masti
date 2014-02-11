#include "common.h"
void print(node *list){
	while(list!=NULL)
	{
		printf("%c",list->a);
		if(list->next->next==NULL){return;}
		//print(list->next);
		list = list->next;
	}
	// printf("\n");
	return;
}