#include "common.h"
void writefile(node *list, FILE *target);
void merge(node *l1, node *l2, node *l3);
void print(node *list);
void create(node *list, FILE *source);

node * reverse(node * cur) {
if(cur->next==NULL) return cur;
node *tmp = reverse(cur->next);
cur->next->next = cur;
cur->next = NULL;
return tmp;
}

void isPalindrome(node *l1, node *l2){
	while(l2->next!=NULL){
		printf("\n %c of l1 is compared with %c of l2", l1->a, l2->a);
		if(l1->a!=l2->a){
			printf("\nNot a Palindrome");
			return;
		}
		l1=l1->next;
		l2=l2->next;
	}
	printf("\nIs a Palindrome");
}

int main(int argc, char **argv){
	node *l1,*l2;
	l1=(node *)malloc(sizeof(node));
	FILE *source=fopen("test.txt","r");
	create(l1, source);
	fclose(source);
	print(l1);
	printf("\n");
	l2 = reverse(l1);
	print(l2);
	isPalindrome(l1, l2);
	return 0;
}


