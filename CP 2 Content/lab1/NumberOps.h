/*
 * Author  : Murali P
 * Created : 12-8-2010
 * Purpose : Assisted Lab1 for DSA 2010
 *
 * Description:  the Number ADT
 * */
#ifndef __NUMBER_OPS_H
#define __NUMBER_OPS_H

#include "Number.h"

#include <stdio.h>
#include <string.h>


extern Number createNumber(char *number_format);

extern Number add(Number a, Number b);

extern Number subtract(Number a, Number b);

extern void printNumber(Number n);
extern Number convert(Number old, int to_base);


#endif
