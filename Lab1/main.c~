/*Program to copy contents of one .txt file to another */
#include<stdio.h>
#include<stdlib.h>
int main(int argc, char *argv[]){
    //char ch;
    FILE *source = fopen(argv[1],"r");
    FILE *target = fopen(argv[2],"w");

    if( source == NULL )
   {
      printf("Source is NULL. Press any key to exit...\n");
      exit(EXIT_FAILURE);
   }
   if (target == NULL){
   	target = stdout;
   }

copy(source,target);

   return 0;
}
