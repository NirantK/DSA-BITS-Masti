#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct ll{
	char a[10];
	struct ll *next;
};
FILE *f1;
typedef struct ll node;

void create(node *list)
{	
//if(strcmp(list->a,"\0"))
	if(fscanf(f1,"%s ",list->a)!=EOF)
	{
		list->next=(node*)malloc(sizeof(node));
		create(list->next);
	}
	else{
		
		list->next=NULL;
		return;
	}
	
	return;
}

void print(node *list){
	if(list->next!=NULL)
	{
		printf("%s ",list->a);
		if(list->next->next==NULL)
		{
			return;
			//printf("%c\n",list->next->a);
		}
		print(list->next);
	}
	return;
}

void copy1(node *list,node *copy)
{

	if(list->next!=NULL)
	{
		copy->next=(node*)malloc(sizeof(node));
		strcpy(copy->a,list->a);
		copy1(list->next,copy->next);
	}
	else
		{
			copy->next=NULL;
	return;
}
}
int main(){
	node *head,*copyhead;
	head=(node *)malloc(sizeof(node));
	copyhead=(node *)malloc(sizeof(node));
	f1=fopen("test.txt","r");
	create(head);
	fclose(f1);
	print(head);
	copy1(head,copyhead);
	printf("\n Copied one is : \n");
	print(copyhead);
	return 0;
}