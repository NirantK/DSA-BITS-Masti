//********* method2.c ******************  Merge Sort ***********************

#include "ListOps.h"
#include <stdio.h>
#define MAX 9999999

void mergeSort(List list , int left, int right);
void merge(List list,int left,int mid,int right);


void Sort(List list , int size){
	mergeSort(list,0,size-1);
}

void mergeSort(List list , int left, int right){
	if(left == right)
		return;
	else{
		int mid = (left+right)/2;
		mergeSort(list,left,mid);
		mergeSort(list,mid+1,right);
		merge(list,left,mid,right);
	}
}

void merge(List list,int left,int mid,int right){
	int i;
	node list1[mid-left+2];
	node list2[right-mid+1];
	node list3[right-left+1];

	list1[mid-left+1].data  = MAX;
	list2[right-mid].data = MAX;
	
	//printf("\nGoing to merge these two lists left :%d mid: %d right :%d \nFirst :",left,mid,right);
	
	int pnt=0;
	for(i=left;i<=mid;i++){
		list1[pnt++].data = ((*list)+i)->data;
	//	printf("%d ",list1[pnt-1].data); 
	}
	pnt=0;
//	printf("\nSecond :");
	for(i=mid+1;i<=right;i++){
		list2[pnt++].data = ((*list)+i)->data;
	//	printf("%d ",list2[pnt-1].data);
	}
		
	int p=0,q=0;

	for(i=0;i<=right-left;i++){
		if(list1[p].data < list2[q].data){
			list3[i].data = list1[p].data;
			p++;
		}
		else{
			list3[i].data = list2[q].data;
			q++;
		}
	}

	for(i=0;i<=right-left;i++){
		((*list)+left+i)->data = list3[i].data;
	}
}
