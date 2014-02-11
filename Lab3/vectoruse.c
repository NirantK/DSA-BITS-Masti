#include <stdio.h>
#include "vector.h"
int main() {
// declare and initialize a new vector
	Vector vector;
	vector_init(&vector);
	// fill it up with 150 arbitrary values
	// this should expand capacity up to 200
	int i;
	for (i = 200; i > -50; i--) { vector_append(&vector, i); }
	// set a value at an arbitrary index
	// this will expand and zero-fill the vector to fit
	vector_set(&vector, 4452, 21312984);
	// print out an arbitrary value in the vector
	printf("Heres the value at 27: %d\n", vector_get(&vector, 27));
// we're all done playing with our vector,
// so free its underlying data array
vector_free(&vector);
}
