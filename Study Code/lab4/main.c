#include "recur.h"
#include <stdio.h>

int main(){
        int arr[] = {5,9,8,4,5,4,365,65};
	int size = 8;

	insertionSort_R(arr,0,size-1);
	deDupR(arr,0,size-1,&size);			//our array is sorted and without duplicates
	
	int i=0;
	for(i=0;i<size;i++){
		printf("%d ",arr[i]);
	}

	if(SUBSET_SUM_R(arr,0,size-1,457))
		printf("\nYes possible");
	else
		printf("\nNo not possible");
		
	return 0;
}
