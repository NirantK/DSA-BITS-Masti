/*
 ============================================================================
 Name        : lab1-3_b.c
 Author      : Shikhar
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

typedef struct node1{
	int data;
	struct node1 *next;
}node;

void push(int a,node **head);
void display(node *head);
void merge(node **head1,node **head2,node **head3);

int main(void) {
	node *head1=NULL,*head2=NULL,*head3=NULL;	//making them equals to NULL is a must

	FILE *fp;
	int a;

	fp = fopen("seq1.txt","r");
	while(feof(fp)==0){
		fscanf(fp,"%d",&a);
		push(a,&head1);
	}
	fclose(fp);


	fp = fopen("seq2.txt","r");
		while(feof(fp)==0){
			fscanf(fp,"%d",&a);
			push(a,&head2);
		}
	fclose(fp);


	display(head1);
	display(head2);
	merge(&head1,&head2,&head3);
	display(head3);
	return 0;
}

void push(int n,node **head){
	node *temp;
	temp = (node *)malloc(sizeof(node));
	temp->data = n;
	temp->next = NULL;

	if(*head == NULL){			//when list was initially empty
		*head = temp;
		(*head)->next = NULL;
	}

	else{
		node *p;
		p = *head;
		while((p->next) != NULL){
			p = p->next;
		}
		p->next = temp;
		(p->next)->next = NULL;
	}
}

void display(node *h){
	printf("\nElements are : ");
	while(h != NULL){
		printf("%d ",h->data);
		h = h->next;
	}
}

void merge(node **h1,node **h2,node **head3){
	node *head1,*head2;
	head1 = *h1;
	head2 = *h2;
	while((head1 != NULL) && (head2 != NULL)){
		if((head1->data) < (head2->data)){
			printf("1: '%d' ",head1->data);
			push((head1->data),head3);
			head1 = head1->next;
		}
		else{
			printf("2 : '%d' ",head2->data);
			push(head2->data,head3);
			head2 = head2->next;
		}
	}

	if(head1 == NULL){
		while((head2 != NULL) ){
			printf(" 3 : '%d'",head2->data);
			push(head2->data,head3);
			head2= head2->next;
		}
	}

	else if(head2 == NULL ){
		while(head1 != NULL ){
			printf("4 : '%d'",head1->data);
			push(head1->data,head3);
			head1= head1->next;
		}
	}
}
