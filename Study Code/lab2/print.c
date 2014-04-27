#include "ListOps.h"
#include <stdio.h>

void print(List list,int list_size){
        int i;
        printf("\nElements are:");
        for(i=0;i<list_size;i++){
                printf("%d ",((*list)+i)->data);
        }
}

