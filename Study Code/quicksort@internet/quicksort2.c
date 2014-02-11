/* */
//Quicksort w/o a separate compare or partition function :)
void quicksort(int A[], int lo, int hi) {
  int i, j, pivot, temp;
  if(lo == hi) return; 
  i=lo; 
  j=hi;
  // pivot= A[(lo+hi)/2]; 
  pivot = A[lo];
  /* Split the array into two parts */
  do {    
    while (A[i] < pivot) i++; 
    while (A[j] > pivot) j--;
    if (i<=j) {
      temp= A[i];
      A[i]= A[j];
      A[j]=temp;
      i++;
      j--;
    }
  } while (i<=j);
    
  if (lo < j) quicksort(A, lo, j);
  if (i < hi) quicksort(A, i, hi);
}