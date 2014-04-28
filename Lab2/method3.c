/*#include<stdlib.h>
#include<stdio.h>
int partition( int a[], int l, int r) {
	int pivot, i, j, t;
	pivot = rand() % (r-l+1);
	i = l; j = r+1;
	while(1)
	{
		do ++i; while( a[i] <= pivot && i <= r );
		do --j; while( a[j] > pivot );
		if( i >= j ) break;
		t = a[i]; a[i] = a[j]; a[j] = t;
	}
	t = a[l]; a[l] = a[j]; a[j] = t;
	printf("%d and %d\n",a[i],a[j]);	
	return j;
}

void quickSort( int a[], int l, int r)
{
   int j;

   if( l < r ) 
   {
   	// divide and conquer
       j = partition( a, l, r);
       quickSort( a, l, j-1);
       quickSort( a, j+1, r);
   }
	
}*/
   // int main(){return 0;}
#include <stdio.h>
 
// A utility function to swap two elements
void swap ( int* a, int* b )
{
    int t = *a;
    *a = *b;
    *b = t;
}
 
/* This function is same in both iterative and recursive*/
int partition (int arr[], int l, int h)
{
    int x = arr[h];
    int i = (l - 1);
 	int j;
    for (j = l; j <= h- 1; j++)
    {
        if (arr[j] <= x)
        {
            i++;
            swap (&arr[i], &arr[j]);
        }
    }
    swap (&arr[i + 1], &arr[h]);
    return (i + 1);
}
void quickSort(int A[], int l, int h)
{
    if (l < h)
    {       
        int p = partition(A, l, h); /* Partitioning index */
        quickSort(A, l, p - 1); 
        quickSort(A, p + 1, h);
    }
}