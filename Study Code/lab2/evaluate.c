//*************evaluate.c************

#include "ListOps.h"
#include <stdio.h>
#include <sys/time.h>

int main(int argc, char* argv[]){
        listhead list=NULL;
        int list_size=0;
	FILE *input,*output;
	
	long long time_start, time_end;
	struct timeval tv;

	input = fopen(argv[1],"r");
	
	output = fopen("output.txt","a");
	
	int c;							//Inputting unsorted sequence from file
	while(feof(input) == 0){
		fscanf(input,"%d ",&c);
		list_size++;
		list = (node *)realloc(list,list_size*sizeof(node));
		list[list_size-1].data = c;
	}

        //print(&list,list_size);
	
	gettimeofday(&tv,NULL); 				/*gets the current system time into variable tv */
	time_start = (tv.tv_sec *1e+6) + tv.tv_usec;

	Sort(&list, list_size);

	gettimeofday (&tv, NULL);
	time_end = (tv.tv_sec *1e+6) + tv.tv_usec;

	//print(&list,list_size);
	if(argc == 3){
		output = fopen(argv[2],"a");
		fprintf(output,"\nN : %d \ntime : %ld",list_size,(time_end - time_start));
	}	
	else{
		printf("\nN : %d \ntime : %lld",list_size,(time_end - time_start));
	}
        return 0;
}
