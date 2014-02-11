/*
 * Author  : Murali P
 * Created : 12-8-2010
 * Purpose : Assisted Lab1 for DSA 2010
 *
 * Description:  the type Number is visualized as having base of the num,
 *               the number of digits(gives us the position value of MSD)
 *               and linked list for storing digits from LSD to MSD.
 *               (NOTE: if a digit is zero, even then it will be stored in the 
 *                      this representation. END NOTE)
 * */
#ifndef __NUMBER_H
#define __NUMBER_H

typedef struct __node *Link;

struct __node;

typedef struct __node {
    int position;
    char digit;
//       int value;
    Link next;
} Node;

typedef struct {
    int base;
    int num_digits;
    Link lsd;
} Number;

#endif
