#include "ListOps.h"
#include <stdio.h>

void Sort(List list , int size){
	int i=0,j=0,key;
	for(i=0;i<size;i++){
		key = ((*list)+i)->data;
		j=i-1;
		while(j>=0 && (key < ((*list)+j)->data)){
			((*list)+j+1)->data = ((*list)+j)->data;
			j--;
		}
		((*list)+j+1)->data = key;
	}
}
