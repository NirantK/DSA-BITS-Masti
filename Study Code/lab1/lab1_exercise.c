/*
 ============================================================================
 Name        : lab1_exercise.c
 Author      : Shikhar
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */
#include <stdio.h>
#include <stdlib.h>

typedef struct node{
	int id;
	char name[30];
	int marks;
}node;

//void push(node data,node **head);
//void display(node *head);

int main(void) {
	node *head;
	FILE *fp;
	fp = fopen("info.txt","r");
	if(!fopen) {printf("\nfile not found\n");return 0;}

//	while(!feof(fp)){
		node data;
		fscanf(fp,"%d %d",(data.id),(data.marks));
		printf("id :%d marks: %d\n",data.id,data.marks);
//		break;
//	}
	return 0;
}
