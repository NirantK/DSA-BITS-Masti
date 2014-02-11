/* insort.c  - sorts using insertion sort*/
#include "sort.h"

#include "compare.h"

/* insert - Function private to this file
 *        - inserts x in the corresponding position
 * */

static int insert(Element x, Element Array[], Size size)
{
    int i, j, temp;

    for (j = 0; j < size; j++)
      {
          if (Array[j] > x)
              break;
          if (Array[j] == x)
              return size;
      }

    for (i = size - 1; i >= j; i--)
      {
          Array[i + 1] = Array[i];
      }
    Array[j] = x;

    return size + 1;
}

Size sortArray(Element Array[], Size size)
{
	Size i,s;
	for(i=1; i < size; i++)
			s=insert(Array[i], Array, i);

	return s;
}
