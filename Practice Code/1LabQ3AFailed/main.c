/*Program to copy contents of one .txt file to a LIFO list built using Linked List */
#include<stdio.h>
#include<stdlib.h>
struct LL{
	char c;
	struct LL *next;
};
typedef struct LL node;
void display(node *list);
node *addEntry(node*list, char ch);
node *dupl(node *list);

int main(int argc, char *argv[]){
    char ch;
    FILE *source = fopen("test.txt","r");
    node *head = (node*) malloc(sizeof(node));
    node *temp = (node*) malloc(sizeof(node));
    head->c=fgetc(source);
    head->next=temp;
    while(ch!=EOF){
	ch = fgetc(source);
	temp = addEntry(temp, ch);
	}
    display(head);
}

node * dupl(node *list){

}
