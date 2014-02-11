/*Nirant prefers Sublime Text on Ubuntu instead of the vi, Apologies for poor code styling*/
#include<stdio.h>
#include<stdlib.h>
void printArray(int a[], int n){
	int i;
	for(i=0;i<n;i++){
		printf("%d     ",a[i]);
	}
	printf("\n-------------------\n");
}
int main(){
	int a[] = {3,7,1,5,9,12};
	int n = sizeof(a) / sizeof(int);
	printArray(a,n);
	sort(a, 0, n-1);
	printArray(a,n);
}
void sort(int a[], int p, int r){
	if (p<r){
		int q = (p+r)/2;
		sort(a, p,q);
		sort(a, q+1,r);
		merge(a, p, q, r);
	}
}
void merge(int a[], int p, int q, int r){
	int n1 = q-p+1;
	int n2 = r-q;
	int L[n1], R[n2];
	int i,j,k;
	for(i=0;i<n1;i++){
		L[i] = a[p+i-1];
	}
	printArray(L, n1);
	for(j=0;j<n2;j++){

		R[j] = a[q+j];
	}
	L[n1] = 999;
	R[n2] = 999;
	i=0;
	j=0;
	for(k=p;k<r;k++){
		if(L[i]<=R[j]){
			a[k]=L[i];
			++i;
		}
		else{
			a[k]=R[j];
			++j;
		} 
		}
	}