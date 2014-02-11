#include<stdio.h>
#include<stdlib.h>
void copy(FILE *source, FILE *target){
	char ch;
    while( ( ch = fgetc(source) ) != EOF )
      fputc(ch, target);
    
	if(target==stdout){printf("\nFile Displayed to Terminal\n");}
	else {
		printf("\nFile copied Successfully\n");
}
}
