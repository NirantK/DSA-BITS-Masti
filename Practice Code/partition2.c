int partition2(int *a, int start, int end){
	int x=a[start];
	int j;
	int i=start;
	int t;
	for(j=start+1;j<=end;j++){
		if(a[j]<=x){
			// swap(a[i],a[j]);
			
			t=a[j];
			// printf("%d\n", t);
			a[j]=a[i];
			// printf("%d\n", a[j]);
			a[i]=t;			
			i++;
		}//if ends here
		int size = end - start + 1;
		// printArray(a, 5);
	}//for loop ends here
	t = a[i];
	a[i]=a[end];
	a[end]=t;	
	return i;
}