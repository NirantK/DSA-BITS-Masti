/*driver.c - sample driver file for using the sort
 * */

#include "sort.h"

void printArray(Element Array[], Size size)
{
		int i;
		printf("\n The elements in the array are as follows: \n");
		for(i=0; i< size; i++)
				printf(" %d\t ", (int)Array[i]);
		printf("\n");
}


int main()
{
	Size Number;        //The number of elements in the array.
	Element Array[MAXLEN]; // Array to be searched
	int x;			// Element to search
	int pos, i;

	printf("\nEnter the number of elements in the array: ");
	scanf("%d", &Number);

	printf("\nEnter the elements in order to the Array: \n");
	for(i=0; i < Number; i++)
	{
		printf("Enter the %dth element: ", i);
		scanf("%d", &Array[i]);
	}

	printf("\n Before sorting: ");

	printArray(Array, Number);

	Number = sortArray(Array, Number);


	printf("\n After sorting: ");

	printArray(Array, Number);

	return 0;
}
