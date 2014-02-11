#include<stdio.h>
#include<stdlib.h>
struct LL{
	char c;
		struct LL *next;
		};
		typedef struct LL node;

node *addEntry(node *list,char ch){
          list->c=ch;
          list->next = (node*)malloc(sizeof(node));
 //      printf("%c", list->c);
         return list->next;
}

