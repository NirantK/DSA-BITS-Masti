/*Nirant hates vi, coded in Sublime Text for Ubuntu 13.04*/
#include<stdio.h>
struct node{
       int val;
       struct node *next;
       };
typedef struct node item;
void join(item *t, item*t1, item*root);
// void readFile(item* t, char *name);

int main(int argc, char * argv[]){
   item *root,*t,*root1,*t1,*test,*test1;
   int i=0;
   char ch;
   int arr[5] = {3,7,10,24,45};
   int brr[5] = {9,10,20,21,27};
   root = (item*)malloc(sizeof(item));
   root1 = (item*)malloc(sizeof(item));
   t=root;
   t1=root1;
   //Note that address of two starting heads are stored in t and t1
   //
   while(t!=NULL && t1!=NULL){
       // t->val = arr[i];
       t1->val = brr[i];
       i++;
       if(i<5){
           // t->next = (item*)malloc(sizeof(item));
           t1->next = (item*)malloc(sizeof(item));
           }
		// t = t->next;
		t1 = t1->next;
   }
   readFile(t,&argv[1]);
   t = root;
   t1 = root1;
   display(t);
   join(t, t1, root);		   
   return 0;
}

void readFile(item* t, char* arg){
	char ch;
	int d;
	printf("%s",arg);
	FILE *source = fopen("file1.txt","r");
	if(source==NULL){
		printf("Error");
		exit(1);
	}
	while(t!=NULL && fscanf(source,"%i",&d)!=EOF){
			// ch = fgetc(source);
			// printf("%d\n", d);
			t->val = d;
			t->next = (item*)malloc(sizeof(item));
			printf("%d", t->val);
			t = t->next;
	}
	fclose(source);

	printf("\n---------------------Exiting readFile---------------------\n");	
}