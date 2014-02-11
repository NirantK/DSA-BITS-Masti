/*Nirant prefers Sublime Text on Ubuntu instead of the vi, Apologies for poor code styling*/
#include<stdio.h>
#include<stdlib.h>

// int quicksort(int a[],int start, int end){
// 		int pos;
// 		if(start<end){
			
// 				pos = partition2(a, start, end);
// 				printf("Position received: %d\n", pos);
// 				quicksort(a, start, pos-1);
// 				quicksort(a, pos+1, end);
// 		}
// 		return 0;
// }

int main(){
	// int a[]={45,1,23,-3,6,0,5,9,11};
	int a[]={4,3,1,2,8};
	int n = sizeof(a) / sizeof(int);
	printf("Before Sorting:\n");
	printArray(a,n);
	quicksort(a, 0, n-1);
	printf("After Sorting:\n");
	printArray(a,n);
}
