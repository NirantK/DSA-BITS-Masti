/*
 * Author  : Murali P
 * Created : 12-8-2010
 * Purpose : Assisted Lab1 for DSA 2010
 *
 * Description: Base ADT 
 * */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "BaseOps.h"

//int max_base;


/* initializeBase - takes the FILE containing the 
 *                  characters to be used for representation
 *                  as input and pushes it inside the lookup table.
 *                  This function returns the max base possible
 *                  for this input file.
 * */


int initializeBase(FILE * basefile)
{
    int i;

    int base_index = 0;

    for (i = 0; i < MAX_BASE; i++)
        Base[i] = 0;

    if (feof(basefile))
      {
          fprintf(stderr, "\nCant open nase file\n");
          exit(-1);
      }

    while (!feof(basefile))
      {
          char ch;

          ch = fgetc(basefile);
          if (ch == EOF)
              break;

          if (isspace(ch))
              continue;
          if (isalnum(ch))
            {
                Base[base_index++] = ch;

            }
          if (!isalnum(ch) /* && !isspace(ch) */ )
            {
                fprintf(stderr,
                        "\nNon alnum number %c given in file\n", ch);
                exit(-1);
            }
      }
    return base_index;
}

/* lookup - searches the Base table and returns the array index of
 *          the object when found. Else returns -1.
 *
 * */
int lookup(char c)
{
    int i = 0;

    // XXX: if Base[i] == 0, then it means that no entry for that base.
    for (i = 0; i < MAX_BASE && Base[i] != 0; i++)
      {
          if (Base[i] == c)
              return i;
      }
    return -1;
}
