/*
 * Author  : Murali P
 * Created : 12-8-2010
 * Purpose : Assisted Lab1 for DSA 2010
 *
 * Description:  the Number ADT
 * */
#include "NumberOps.h"
#include "BaseOps.h"

#include <string.h>
#include <stdio.h>

#define MAX_LINE 256

#define getline                                 		    	\
         if( fgets(line, MAX_LINE, fip) == NULL)				\
				  break; 										\
          len = strlen(line);									\
		  line_count++;											\
          if (len <= MAX_LINE)									\
            {													\
                line[len - 1] = '\0';							\
          } else												\
            {													\
                fprintf(stderr, "Length of operand too big\n");	\
                fclose(fip);									\
                exit(-1);										\
            }



typedef enum { ADD, SUBTRACT } Operator;





int main(int argc, char **argv)
{
    FILE *fip, *fbase;

    Number n1, n2, result;      // n[100];

    char line[MAX_LINE];

    if (argc != 3)
      {
          fprintf(stderr, "Usage:  %s <basefile> <inputfile>\n", argv[0]);
          exit(-1);
      }
    // first read the base file
    fbase = fopen(argv[1], "r");
    if (fbase == NULL)
      {
          fprintf(stderr, "Cant open file %s\n", argv[1]);
          exit(-1);
      }
    initializeBase(fbase);
    fclose(fbase);
    // Read the calculator's input file; and feed it to calculator

    fip = fopen(argv[2], "r");
    if (fip == NULL)
      {
          fprintf(stderr, "Cant open file %s\n", argv[2]);
          exit(-1);
      }
    while (!feof(fip))
      {
          int len;

          Operator op;

          int line_count = 0;

          //extract operand
          getline;
          /*
             if (fgets(line, MAX_LINE, fip))
             break;
             len = strlen(line);
             line_count++;

             if (len <= MAX_LINE)
             {
             line[len - 1] = '\0';
             } else
             {
             fprintf(stderr, "Length of operator too big\n");
             fclose(fip);
             exit(-1);
             }
           */
          if (strcmp(line, "add") == 0 || strcmp(line, "ADD") == 0)
            {
                op = ADD;
          } else if (strcmp(line, "subtract") == 0
                       || strcmp(line, "SUBTRACT") == 0)
            {
                op = SUBTRACT;
            } else
            {
                fprintf(stderr, "DEBUG %d: Operator  %d\n", __LINE__,
                        line_count);
                fprintf(stderr, "Invalid Operator %s\n", line);
                fclose(fip);
                exit(-1);
            }
          //extract operator1
          getline;
          n1 = createNumber(line);

//                result=convert(n1, 12);
          printf("Reading ");
          printNumber(n1);
          printf("\n");
          //              fprintf(stderr, "DEBUG %d: in  %s\n",__LINE__, __FILE__);


          //extract operator2
          getline;
          n2 = createNumber(line);

          printf("Reading ");
          printNumber(n2);
          printf("\n");
          //work
          if (op == ADD)
            {
                // case ADD:
                result = add(n1, n2);
                //   break;
          } else if ( /* case */ SUBTRACT)      //:
            {
                result = subtract(n1, n2);
                //    break;
            }
          // default:
            else
            {
                printf("Nothing to do \n");
            }
          //print
          printNumber(n1);
          switch (op)
            {
            case ADD:
                printf(" + ");
                break;
            case SUBTRACT:
                printf(" - ");
            default:
                printf(" ");
            }
          printNumber(n2);
          printf(" = ");
          printNumber(result);
          printf(" \n");
      }                         // !feof

    fclose(fip);
    return (0);
}
