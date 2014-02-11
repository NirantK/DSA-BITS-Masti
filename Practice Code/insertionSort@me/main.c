/*InsertionSort*/
#include <stdio.h>
#define MAXLEN 100000
#include <time.h>
int main(int argc, char **argv){
	clock_t begin, end1, end2;
	/*Read from File to Array*/
	FILE *source = fopen(argv[1],"r");
	int i=0;
	int a[MAXLEN];
	int x;
	if(source==NULL){
		printf("Error\n");
		exit(1);
	}
	while(fscanf(source, "%i", &x)!=EOF){
		// printf("%d\n", x);
		a[i]=x;
		i++;
	}

	/*Sort, Measure sorting and write to file time*/
	begin = clock();	
	int n = sizeof(a) / sizeof(int);
	sort(a, n);
	end1 = clock();
	/*Write to File*/
	FILE *target = fopen("output.txt","w");
	if(target==NULL){
		printf("Error\n");
		exit(1);
	}
	for(i=0;i<n;i++){
		fprintf(target, "%d,\t",a[i]);
	}
	end2 = clock();

	printf("Time taken for the Insertion Sorting is:\t%1.1f\n", (double)end1-begin);
	printf("Time taken for sorting + file writing is:\t%1.2f\n", (double)end2-begin);
	
	return 0;
}