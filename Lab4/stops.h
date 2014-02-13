#include "sttypes.h"
extern Stack newStack(); 
/* Creates an empty stack and initialize it. */

extern Boolean push (Stack st, int data);
/* Pushes data in the stack st and returns TRUE. It returns FALSE if push fails (This case is not handled in the code) . */


extern Boolean pop (Stack st, int* data);
/* Pops the topmost element in data. It returns TRUE on sucessful pop and returns FALSE otherwise.*/


Boolean top (Stack st, int*data );
/* Returns the topmost element in data. It returns TRUE on sucessful top and returns FALSE otherwise.*/

extern int size(Stack st); 
/* Returns the number of elements in the stack. Returns -1 otherwise.  */

extern void display (Stack); 

/* Displays the contents of the stack */



