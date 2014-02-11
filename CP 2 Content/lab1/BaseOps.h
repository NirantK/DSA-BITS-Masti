/*
 * Author  : Murali P
 * Created : 12-8-2010
 * Purpose : Assisted Lab1 for DSA 2010
 *
 * Description: Base ADT 
 * */

#ifndef __BASE_OPS_H
#define __BASE_OPS_H

#include "Base.h"
#include <stdio.h>
#include <stdlib.h>

/* initializeBase - takes the FILE containing the 
 *                  characters to be used for representation
 *                  as input and pushes it inside the lookup table.
 * */

extern int initializeBase(FILE * basefile);

/* lookup - searches the Base table and returns the array index of
 *          the object when found. Else returns -1.
 *
 * */
extern int lookup(char c);


#endif
