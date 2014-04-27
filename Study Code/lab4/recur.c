#include <stdio.h>
#include "recur.h"

void insertionSort_R ( int arr[], int first, int last){
	if(first==last)
		return;
	else{
		insertionSort_R(arr,first,last-1);
		
		int i,key;
		key=arr[last];

		for(i=last-1; i>=first ;i--){
			if(arr[i] < key){
				arr[i+1] = key;
				return;
			}
			arr[i+1] = arr[i];
		}
		arr[i+1] = key;
	}
}


void deDupR(int arr[],int first,int last,int *size){
	if(first == last)
		return;

	else if(arr[first] != arr[first+1]){
		deDupR(arr,first+1,last,size);
	}
	else{
		int i;
		for(i=first+1;i<last;i++){
			arr[i] = arr[i+1];
		}
		(*size)--;
		deDupR(arr,first+1,last-1,size);
	}
}

int SUBSET_SUM_R(int arr[],int start,int end, int T){
	printf("\nstart :%d end :%d T :%d",start,end,T);
	if(T==0){
		printf(" returned 1");
		return 1;
	}

	else if(T<0 || end<0){
		printf(" returned zero");
		return 0;
	}
	printf(" going for more recursion");
	return (SUBSET_SUM_R(arr,start,end-1,T) || SUBSET_SUM_R(arr,start,end-1,T-arr[end]));
}
























