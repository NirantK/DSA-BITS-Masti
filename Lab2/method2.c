/*Merge Sort*/
int merge(int arr[], int l, int m, int h)
{
    int n1, n2, i, j, k;
    n1 = m - l + 1;
    n2 = h - m;
    int arr1[n1], arr2[n2];

    for(i = 0; i < n1; i++)
        arr1[i] = arr[l + i];

    for(j = 0; j < n2; j++)
        arr2[j] = arr[m + j + 1];

    arr1[i] = 9999;
    arr2[j] = 9999;

    i = 0;
    j = 0;

    for(k = l; k <= h; k++)
    {
        if(arr1[i] <= arr2[j])
            arr[k] = arr1[i++];
        else
            arr[k] = arr2[j++];
    }

    return 0;
}
int mergesort(int arr[],int low,int high)
{
    // printf("\nmerge_sort initialization\n");

    int mid;

    if(low < high) 
    {
        mid = (low + high) / 2;

        // Divide and Conquer
        mergesort(arr, low, mid); 
        // printf("\n merge_sort first\n");

        mergesort(arr, mid + 1, high); 
        // printf("\n merge_sort second\n");

        // Combine
        merge(arr, low, mid, high); 
        // printf("\nmerging\n");
    }

    return 0;
}

