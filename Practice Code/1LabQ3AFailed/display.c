#include<stdio.h>
#include<stdlib.h>
struct LL{
	char c;
	struct LL *next;
};
typedef struct LL node;
void display(node *list){ 
        if(list->next!=NULL){
                printf("%c->",list->c);
                if(list->next->next == NULL){
                        printf("%c", list->next->c);
                        }       

                display(list->next);
        }

}
