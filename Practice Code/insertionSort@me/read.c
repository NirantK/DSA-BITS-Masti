#include<stdio.h>
int* readFile(){
	FILE *source = fopen("input10.txt","r");
	int x,i=0;
	int a[10];
	if(source==NULL){
		printf("Error");
		exit(1);
	}
	while(fscanf(source, "%i", &x)!=EOF){
		printf("%d\n", x);
		a[i]=x;
		i++;
	}
	return *a;
}