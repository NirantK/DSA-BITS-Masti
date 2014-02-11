#include<stdio.h>
struct node{
int id;
int marks;
char *name;
struct node *next;
};
typedef struct node item;
int main(){
item *arr,*root;
arr = (item*)malloc(sizeof(item));
root = arr;
arr->id = 392;arr->marks=93;arr->name = "Prateek";
arr->next = (item*)malloc(sizeof(item));
arr = arr->next;
arr->id = 430;arr->marks=90;arr->name = "Shikhar";
arr->next = (item*)malloc(sizeof(item));
arr = arr->next;
arr->id = 612;arr->marks=91;arr->name = "Jashan";
arr->next = (item*)malloc(sizeof(item));
arr = arr->next;
arr->id = 071;arr->marks=91;arr->name = "Vishal";
arr->next = (item*)malloc(sizeof(item));
arr = arr->next;
arr->id = 441;arr->marks=92;arr->name = "Maurya";
item *rooter;
int a;char *c;
for(arr = root;arr!=NULL;arr=arr->next){
for(rooter = arr->next;rooter!=NULL;rooter=rooter->next){
if(arr->marks < rooter -> marks){
              a = arr->id;
			arr->id = rooter->id;
			rooter->id = a;
			a = arr->marks;
			arr->marks = rooter->marks;
			rooter->marks = a;
			c = arr->name;
			arr->name = rooter->name;
			rooter->name = c;
            }
if(arr->marks == rooter->marks){
if(arr->id > rooter->id){
	    	a = arr->id;
			arr->id = rooter->id;
			rooter->id = a;
			a = arr->marks;
			arr->marks = rooter->marks;
			rooter->marks = a;
			c = arr->name;
			arr->name = rooter->name;
			rooter->name = c;
            }
}
}
}
for(arr = root;arr!=NULL;arr=arr->next)
{printf("\n%s",arr->name);
}
return 0;
}
