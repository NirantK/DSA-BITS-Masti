void sort(int a[],int n){
	int i,j,x;
	for(i=0;i<n;i++){
		x=a[i];
		j = i;		
		while(j>0 && a[j-1]>x){
			a[j]=a[j-1];
			j--;
		}
		a[j]=x;
	}
}