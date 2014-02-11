/*Program to copy contents of one .txt file to a LIFO list built using Linked List */
#include<stdio.h>
#include<stdlib.h>
struct LL{
	char c;
	struct LL *next;
};
typedef struct LL node;

void print(node*list);
int main(int argc, char *argv[]){
    char ch;
    FILE *source = fopen("test.txt","r");
    //FILE *target = fopen(argv[2],"w");
	node *head;
    if( source == NULL )
   {
      printf("Press any key to exit...\n");
      exit(EXIT_FAILURE);
   }
  	node *list;
	list = (node*) malloc(sizeof(node));
  	list->next=NULL;
	list->c='c';
	fclose(source);

	print(head);
	return 0;
}

void print(node *list){
	if(list->next != NULL){
		printf("%c",list->c);
		if(list->next->next==NULL)
			printf("%c",list->next->c);

		print(list->next);
	}
	else{
	printf("%c", list->c);
	}
}
