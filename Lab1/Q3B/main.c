#include "common.h"
void writefile(node *list, FILE *target);
void merge(node *l1, node *l2, node *l3);
void print(node *list);
void create(node *list, FILE *source);

int main(){
	node *l1,*l2, *l3;
	l1=(node *)malloc(sizeof(node));
	l2=(node *)malloc(sizeof(node));
	l3=(node *)malloc(sizeof(node));
	FILE *source=fopen("input1.txt","r");
	create(l1, source);
	source = fopen("input2.txt","r");
	create(l2, source);
	fclose(source);
	// print(l1);
	printf("\n");
	// print(l2);
	printf("\n");
	merge(l1, l2, l3);
	printf("**************************************************************************\nMerged one is :\n");	
	// print(l3);
	printf("\n");
	FILE *target = fopen("out.txt","w");
	writefile(l3, target);
	return 0;
}

