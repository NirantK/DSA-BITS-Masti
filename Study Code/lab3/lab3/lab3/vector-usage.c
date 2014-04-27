#include <stdio.h>
#include "vector.h"

int main(){
	Vector vector;
	vector_init(&vector);

	int i;
	for (i = 200; i > -50; i--) { vector_append(&vector, i); }

	vector_set(&vector, 4452, 21312984);
	printf("Heres the value at 27: %d\n", vector_get(&vector, 27));
	printf("%d",vector.capacity);
	vector_free(&vector);
}
