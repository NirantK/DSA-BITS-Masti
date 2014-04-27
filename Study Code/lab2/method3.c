// ********* method3.c ***** Quick Sort *******************
#include "ListOps.h"
#include<stdio.h>
#include<stdlib.h>

Location doPartition(List list, Location left,Location right){
	int size = right - left+1;
	int pivot = left+(rand() % size);
		int temp;					//swapping random and last element
		temp = ((*list)+pivot)->data;
		((*list)+pivot)->data = ((*list)+right)->data;
		((*list)+right)->data = temp;
	
	int val_at_pivot = temp;
	int i=left-1;
	int j=left;

	for(j=left;j<=right-1;j++){
		if( ((*list)+j)->data  < val_at_pivot){
			i++;
			temp = ((*list)+i)->data;
			((*list)+i)->data = ((*list)+j)->data;
			((*list)+j)->data = temp;
		}
	}
	temp = ((*list)+i+1)->data;
        ((*list)+i+1)->data = ((*list)+right)->data;
        ((*list)+right)->data = temp;
	
	return i+1;
}

void quick_sort(List list, Location left, Location right){
	if(left >= right)					//terminating condition
		return;
	
	Location pivot = doPartition(list,left, right);
	quick_sort(list,left,pivot-1);
	quick_sort(list,pivot+1,right);
	
}

void Sort(List list,int size){
        quick_sort(list,0,size-1);
}





