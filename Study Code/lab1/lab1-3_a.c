/*
 ============================================================================
 Name        : lab1-3_a.c
 Author      : Shikhar
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

typedef struct node{
	char data;
	struct node *next;
}node;

void push(char c,node **head);
void display(node *head);
void copy(node *h1,node **h2);
int pallin(node *h1, node *h2);

int main(void) {
	node *head1=NULL,*head2=NULL;

	FILE *fp;
	fp = fopen("text.txt","r");
	char c;

	while(feof(fp)==0){
		fscanf(fp,"%c ",&c);
		printf("%c ",c);
		push(c,&head1);
	}

	copy(head1,&head2);
	display(head1);
	display(head2);

	if(pallin(head1,head2))
		printf("\n Yes Pallindrome");

	else
		printf("\n No not Pallindrome");

}

void push(char c,node **h){
	node *temp;
	temp = (node *)malloc(sizeof(node));
	temp->data =c;
	temp->next =NULL;

	if((*h) == NULL){
		*h = temp;
	}
	else{
		temp->next = (*h);
		(*h) = temp;
	}
}

void display(node *h){
	printf("\n Elements are :");
	while(h != NULL){
		printf("%c ",h->data);
		h = h->next;
	}
}

void copy(node *h1,node **h2){
	while(h1 != NULL){
		push(h1->data, h2);
		h1 = h1->next;
	}
}

int pallin(node *h1,node *h2){
	while(h1 != NULL){
		if(h1->data != h2 ->data)
			return 0;
		else{
			h1 = h1->next;
			h2 = h2->next;
		}
	}
	return 1;
}
