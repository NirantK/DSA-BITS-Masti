#include "iterate.h"
#include <stdio.h>


void insertionSort_I(int arr[],int start,int end){
	int i,j,key;

	for(i=1;i<=end;i++){
		key = arr[i];

		for(j=i-1;j>=0;j--){
			if( key >= arr[j]){
				arr[j+1] = key;
				break;
			}
			arr[j+1] = arr[j];
		}
	}
}
