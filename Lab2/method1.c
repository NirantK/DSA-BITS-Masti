/*for i ← 1 to length(A)
    x ← A[i]
    j ← i
    while j > 0 and A[j-1] > x
        A[j] ← A[j-1]
        j ← j - 1
    A[j] ← x*/

int insertSort(int arr[], int n){
	int i,j;
	for(i=0;i<n;i++){
		int x = arr[i];
		j=i;
		while(j>0 && arr[j-1]>x)
		//change inequality to sort ascending or descending
		{
			arr[j]=arr[j-1];
			j -= 1;
		}
		arr[j] = x;
	}
	return 0;
}