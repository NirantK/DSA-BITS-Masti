#include "common.h"

void merge(node *l1, node *l2, node *l3){
	while(l1->next!=NULL && l2->next!=NULL)
	{
		if(l1->a < l2->a){
			l3->a = l1->a;
			l1=l1->next;
		}
		else{
			l3->a = l2->a;
			l2=l2->next;
		}
		l3->next=(node*)malloc(sizeof(node));
		l3=l3->next;
		l3->next=NULL;
	}
	while(l1->next!=NULL){
		l3->a = l1->a;
		l1=l1->next;
		l3->next=(node*)malloc(sizeof(node));
		l3=l3->next;
		l3->next=NULL;
	}
	while(l2->next!=NULL){
		l3->a = l2->a;
		l2=l2->next;
		l3->next=(node*)malloc(sizeof(node));
		l3=l3->next;
		l3->next=NULL;
	}
}