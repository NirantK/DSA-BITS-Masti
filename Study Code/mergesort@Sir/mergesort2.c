/*mergesort1.c  -  mergesort version 1*/
#include "sort.h"

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

    int i, j, k;

    k = 1;

    while (k < size)
      {
          for (j = 0; j < size; j = j + 2 * k)
            {
                int start1, start2, end1, end2;

                start1 = j;
                if (start1 + k  >= size)
                  {
                      end1 = size - 1;
                      copyArray(Array, new, start1, end1);
                  } else
                  {
                      end1 = start1 + k  - 1;
                      start2 = j + k;
                      end2 = (start1 + 2 * k - 1 >= size) 
					           ? size - 1 : start2 + k - 1;
                      // Note that start2 + k - 1 is equivalent to (start1+2*k -1)
                      merge(Array, start1, end1, start2, end2, new);
                  }
			}

            copyArray(new, Array, 0, size - 1);
            k = 2 * k;
      }
      return size;          // forced to return size because of prototype.
}
