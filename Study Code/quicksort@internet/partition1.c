int partition1(int a[], int start, int end){
	int pos = start;
	int i, t, temp;
	for(i=start;i<end;i++){
		if(a[i]<a[end]){
			//swap(a[i], a[pos]);
			t = a[i];
			a[i] = a[pos];
			a[pos] = t;
		}
	}//for loop ends here
	t = a[pos];
	a[pos]=a[end];
	a[end]=t;
}