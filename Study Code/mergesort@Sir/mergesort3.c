/*mergesort1.c  -  mergesort version 3 == using log2 fn */
#include "sort.h"
#include <math.h>

static void merge(Element Array[], int start1, int end1,
                  int start2, int end2, Element newArray[])
{
    Size size1 = end1 - start1 + 1;

    Size size2 = end2 - start2 + 1;

    int i = start1, j = start2;

    int k = start1;

    while (i <= end1 && j <= end2)
      {
          if (Array[i] <= Array[j])
            {
                newArray[k] = Array[i];
                k++;
                i++;
            } else
            {
                newArray[k] = Array[j];
                k++;
                j++;
            }
      }
    if (i <= end1)              // if first sublist didnt complete
      {
          for (; i <= end1; i++)
            {
                newArray[k] = Array[i];
                k++;
            }
      } else                    /* if ( j<=end2) */
      {
          for (; j <= end2; j++)
            {
                newArray[k] = Array[j];
                k++;
            }
      }
    return;
}

static void copyArray(Element src[], Element dest[], int start, int end)
{
    int i;

    for (i = start; i <= end; i++)
        dest[i] = src[i];
    return;
}

/* sortArray - Uses merge sort algorithm for sorting the Array
 * */
Size sortArray(Element Array[], Size size)
{
    Element new[MAXLEN];

    int i, j, k, start;

    k = 1;

    for (i = 0; i < ceil((log(size)) / (log(2))); i++)
	{
          for (j = 0; j <= (ceil(((float) (size) / (float) (2 * k)))); j++)
            {
                start = 2 * k * j;
                if (start < size)
                  {
                      if ((start + k) >= size)
                        {
								copyArray(Array, new, start, size-1);
                        } else
                        {
                            if ((start + (2 * k) - 1) >= size)
                                merge(Array, start, (start + k - 1),
                                      (start + k), (size - 1), new);
                              else
                                merge(Array, start, (start + k - 1),
                                      (start + k), (start + (2 * k) - 1),
                                      new);
                        }
                  }
            }
          copyArray(new, Array, 0, size - 1);
          k = k * 2;

	}
    return size;                // forced to return size because of prototype.
}

