#include "common.h"
/*void writefile(node *list, FILE *target);
void merge(node *l1, node *l2, node *l3);*/
void print(contact *list);
void create(contact *list, FILE *source);

int main(int argc, char *argv[]){
	FILE *source = fopen("input.txt", "r");
	contact *phbook = (contact*)malloc(sizeof(contact));
	create(phbook, source);
	print(phbook);
	return 0;
}
