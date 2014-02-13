#include <stdio.h>
#include<stdlib.h>
#include "stops.h"

Stack newStack()
{
	Stack st = (Stack) malloc (sizeof (struct stack)); 
	st->top=NULL;
	st->size=0; 
	
	return st; 
}

Boolean push (Stack st, int data)
{
	
	if (st==NULL)
		{
			printf("\n Error-Push: Stack Non Existent");
			return FALSE;
		}
	
	Elem el = (Elem) malloc (sizeof (struct node)); 
	el->next=NULL;
	el->data= data;
			
			if(st->top==NULL)
			{
				st->top=el;
				st->size=1;
			}
			else {
				el->next=st->top;
				st->top=el;
				st->size++;
			}
			return TRUE; 
	
	
}
Boolean pop (Stack st, int* data){
	Elem el=NULL;
	if (st==NULL)
		{
			printf("\n Error-Pop: Stack Non Existent");
			return FALSE;
		}
	if (st->top==NULL)
		{
			printf("\n Error-Pop: Empty Stack");
			return FALSE;
		}
	
	el=st->top;
	*data=el->data;
	st->top=el->next;
	free(el);
	return TRUE; 	
}


Boolean top (Stack st, int* data){
	Elem el=NULL;
	if (st==NULL)
		{
			printf("\n Error-Top: Stack Non Existent");
			return FALSE;
		}
	if (st->top==NULL)
		{
			printf("\n Error-Top: Empty Stack");
			return FALSE;
		}
	
	el=st->top;
	*data=el->data;
	return TRUE; 	
}

int size(Stack st){
if (st==NULL)
		{
			printf("\n Error-Pop: Stack Non Existent");
			return -1;
		}
return st->size; 
}

void display (Stack st)
{

	if (st==NULL)
		{
			printf("\n Error-Display: Stack Non Existent");
			
		}
	else{
		printf("\n Stack-Display : ");
		Elem curr=st->top;
	
		while(curr!=NULL)
		{
			printf("\n %d", curr->data);
			curr=curr->next;
		}
		
		printf("\n Stack-Display ends \n");
	
	}
	
}
