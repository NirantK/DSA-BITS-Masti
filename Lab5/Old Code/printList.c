#include "offense.h"

void printVehicleList(owner node)
{
	if(node->next!=NULL){
		node = node -> next;
	}
  while(node!=NULL)
  {
   	printf("%d,%d", node->uid, node->vno);
	printf("\n");
   node = node->next;
  }
}

void printDriversList(driver node)
{
	if(node->next!=NULL){
		node = node -> next;
	}
  while(node!=NULL)
  {
   	printf("%d,%d", node->uid, node->lic);
	printf("\n");
   node = node->next;
  }
}

void printOffensesList(offense node)
{
	if(node->next!=NULL){
		node = node -> next;
	}
  while(node!=NULL)
  {
   	printf("%d,%d", node->lic, node->pen);
	printf("\n");
   node = node->next;
  }
}