#include<stdio.h>
struct node{
       int val;
       struct node *next;
       };
typedef struct node item;
void display(item *t);
void join(item *t, item*t1, item*root){
	item *test,*test1;
while(t!=NULL && t1!=NULL){           
				if(t->val <= t1->val){
					test = t->next;
					if(test!=NULL){
						if(test->val >= t1->val){
							test1 = t1->next;
							t->next = t1;
							t1->next = test;
							t1 = test1;
							t = t->next;
						}
						else t = t->next;
			}
					else test = t1;
				}
				else{
					test1 = t1->next;
					t1->next = t;
					t1 = test1;
				}
			}

			if(t==NULL){
				t = t1;
			}else{
				t1 = t;
				}
			t = root;
			display(t);
}
void display(item *t){
				while(t){
				printf("%d\n",t->val);
				t = t->next;
			}
}