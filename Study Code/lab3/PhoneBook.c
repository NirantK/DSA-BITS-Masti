#include "PhoneBook.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

PHBOOK* createAddressBook(){
	PHBOOK* temp;
	temp = malloc(sizeof(PHBOOK));
	temp->size = 0;
	temp->capacity = MAX_CAPACITY;
	temp->next = NULL;
	return temp;	
}

int isNotFull(PHBOOK* head){
	if(head->size >= head->capacity)
		return -1;
	else
		return head->size;
}

int isEmpty(PHBOOK* head){
	if(head->size == 0)
		return -1;
	else
		return head->size;
}

void printAddressBook(PHBOOK *head,FILE *output){
	Contact* p;
	p = head->next;
	int i;
	for(i=0;i< head->size;i++){
		fprintf(output,"Name: %s Mobile number: %d\n",p->name,p->mobile_number);
		p = p->next;
	}
}

Contact* searchByName(PHBOOK *pb,char name[]){
	Contact *fnode;
	fnode = pb->next;
	int i;
	for(i=0;i< pb->size;i++){
		if(strcmp(name,fnode->name))
			return fnode;
		p = p->next;
	}
	return NULL;
}

PHBOOK* insertAddress(PHBOOK *pb,Contact con){

	Contact *temp;
	temp = (Contact *)malloc(sizeof(Contact));
	strcpy(temp->name,con.name);
	temp->mobile_number = con.mobile_number;

	if(pb->size == 0){				//case when phone book is initially empty
		pb->next = temp;
		temp->next = temp;
		pb->size++;
		return pb;
	}
	
	pb->size++;
							//when list is not empty
	Contact *fnode = pb->next;

	if(strcmp(temp->name,fnode->name) <= 0 ){	//new contact has to take the place of the first contact
		
		Contact *last;
		last=fnode;
		while(last->next != fnode)
			last = last->next; 
 		
		last->next = temp;
		temp->next = fnode;
 
		return pb;
	}
	
	Contact *p,*prev;
	prev = fnode;
	p = fnode->next;
	while(p != fnode){				//if new contact has to be added in between
		if(strcmp(temp->name,p->name)<=0){
			prev->next = temp;
			temp->next = p;
			return pb;
		}
		
		prev=p;
		p=p->next;
	}
	prev->next = temp;				//if contact has to be added at the last position
	temp->next = fnode;
	return pb;
}

Contact* deleteAddress(Contact *fnode,Contact con){
	if(strcmp(fnode->name,con.name) == 0){

		Contact *last;
                last=fnode;
                while(last->next != fnode)
                        last = last->next;

                last->next = fnode ->next;
		free(fnode);
		fnode = last->next;
		return fnode;
	}

	Contact *p,*prev;
	prev = fnode;
	p = fnode->next;

	while(p != fnode){
		if(strcmp(con.name,p->name)==0){
			prev->next = p->next;
			free(p);
			return fnode;
		}
	}
} 

PHBOOK* deleteAllAddresses(Contact *fnode){
	Contact *p;
	p=fnode->next;
	while(p != fnode)
		free(p);
	free(p);
	return createAddressBook();
}

PHBOOK* uploadAddresses(PHBOOK* ph,char fname[]){
	FILE *input;
	input = fopen(fname,"r");
	char *name;
	int mobno;
/*
	while(feof(input)==0){
		fscanf(input,"%s %d",name,&mobno);
		Contact con;
		strcpy(con.name,name);
		con.mobile_number = mobno;

		ph->size++;
		ph->next = insertAddress(ph->next,con);
	}*/
}


















