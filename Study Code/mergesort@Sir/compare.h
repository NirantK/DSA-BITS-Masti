/**  compare.h - Interface file for modified ordered function
*/


typedef enum {LESSER=-1, GREATER=1, EQUAL=0} ORDER;


/*  compare- returns whether the a comes here b or not.
*/
extern ORDER compare(Element a, Element b);

