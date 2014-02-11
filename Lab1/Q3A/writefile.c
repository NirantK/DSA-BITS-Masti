#include "common.h"
void writefile(node *list, FILE *target){
	while(list->next!=NULL){
	fprintf(target, "%d ", list->a);
	list=list->next;
	}
}