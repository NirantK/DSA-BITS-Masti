#include <stdio.h>
#include <sys/time.h>
#include <stdlib.h>
#include <time.h>
#define MAXLEN 100000
int mergesort(int arr[],int low,int high);
int insertSort(int arr[], int n);
int quickSort(int arr[], int lo, int hi);
int x[MAXLEN];
double print_time( clock_t time)
{
    /*  Function calculates time elapsed after the "time" variable was set
     *  Accepts clock_t variable and returns time in seconds
     */
    
    return ((double)(clock() - time)/CLOCKS_PER_SEC);
}
int readFile(int argc, char **argv){
	int i=0;
	if(argc<=1){
		printf("Please enter filename.\n");
		exit(1);
	}
	FILE *fp = fopen(argv[1], "r");
	if(fp==NULL){
		printf("File not found. \n");
	}
	while(fscanf(fp,"%d\n",&x[i] )!=EOF){
		// printf("%d\n",x[i] );
		i++;
	}
	return i;
}
int main(int argc, char **argv){
	// int x[MAXLEN];
	int i = readFile(argc, argv);
	clock_t time;
	FILE *out = fopen("output.txt", "w");	
	int max = (i<MAXLEN)?i:MAXLEN;
	/*Sort*/
	time = clock();
	// insertSort(x, max);

    printf("Sorting using insertion sort took %6.10f s\n", print_time(time));	
	time = clock();
	i = readFile(argc, argv);
	max = (i<MAXLEN)?i:MAXLEN;
	// mergesort(x,0,max);
	
    printf("Sorting using mergesort took %6.10f s\n", print_time(time));	
	time = clock();
	i = readFile(argc, argv);
	max = (i<MAXLEN)?i:MAXLEN;
	quickSort(x, 0, max);
	while(i>0){
		// printf("%d\n", x[i]);
		fprintf(out, "%d\n", x[i]);
		i--;
	}
    printf("Sorting using quickSort took %6.10f s\n", print_time(time));	
	/*write output to file*/

	return 0;
}