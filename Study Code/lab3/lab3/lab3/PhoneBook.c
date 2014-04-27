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

Contact* searchByName(PHBOOK *head,char name[]){
	Contact *p;
	p = head->next;
	int i;
	for(i=0;i< head->size;i++){
		if(strcmp(name,p->name))
			return p;
		p = p->next;
	}
	return NULL;
}

Contact* insertAddress(Contact *fnode,Contact con){
	Contact *p,*prev;
	if(strcmp(con.name,fnode->name) <= 0 ){
		
		Contact *last;
		last=fnode;
		while(last->next != fnode)
			last = last->next; 
 		
		last->next = &con;
		con.next = fnode;
 

/*
 		char nametemp[30];
                int mobtemp;
		strcpy(nametemp,fnode->name);
		mobtemp = fnode->mobile_number;
		strcpy(fnode->name,con.name);
		fnode->mobile_number = con.mobile_number;
		
		strcmp(con.name,nametemp);
		con.mobile_number = mobtemp;

		con.next = fnode->next;
		fnode->next = &con;
*/
		return fnode;
	}
	
	prev = fnode;
	p = fnode->next;
	while(p != fnode){
		if(strcmp(con.name,p->name)<=0){
			prev->next = &con;
			con.next = p;
			return fnode;
		}
		
		prev=p;
		p=p->next;
	}
	prev->next = &con;
	con.next = fnode;
	return fnode;
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

	while(feof(input)==0){
		fscanf(input,"%s %d",name,&mobno);
		Contact con;
		strcpy(con.name,name);
		con.mobile_number = mobno;

		ph->size++;
		ph->next = insertAddress(ph->next,con);
	}
}


















