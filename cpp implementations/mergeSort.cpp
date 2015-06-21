#include<iostream>
// #define MAXSIZE 2000
using namespace std;
// void merge(int*,int,int,int);
// void mergeSort(int a[], int l, int r){
//     if(r-l>1){
//         int mid=(l+r)/2;
//         mergeSort(a,l,mid);
//         mergeSort(a,mid+1,r);
//         merge(a,l,r,mid);
//     }
// }
// void merge(int a[],int l,int h,int m){
//     int i=l,j=m+1,k=l;
//     int c[MAXSIZE];
//     while(i<=m && j<=h){
//         if(a[i]<a[j]){
//             c[k]=a[i];
//             i++;
//         }
//         else{
//             c[k]=a[j];
//             j++;
//         }
//         k++;
//     }
//     while(i<=m){
//         c[k]=a[i];
//         i++;
//         k++;
//     }
//     while(j<=h){
//         c[k]=a[j];
//         j++;
//         k++;
//     }
//     for(int i=0;i<k;i++){
//         a[i]=c[i];
//     }
// }
// int main(){
//     int a[10];
//     for(int i=0;i<10;i++)
//         cin>>a[i];
//     mergeSort(a,0,9);
//     for(int i=0;i<10;i++){
//         cout<<a[i]<<"  ";
//     }
// }


void merge(int arr[], int l, int m, int r)
{
    int i, j, k;
    int n1 = m - l + 1;
    int n2 =  r - m;

    /* create temp arrays */
    int L[n1], R[n2];

    /* Copy data to temp arrays L[] and R[] */
    for(i = 0; i < n1; i++)
        L[i] = arr[l + i];
        for(j = 0; j < n2; j++)
            R[j] = arr[m + 1+ j];

            /* Merge the temp arrays back into arr[l..r]*/
            i = 0;
            j = 0;
            k = l;
            while (i < n1 && j < n2)
            {
                if (L[i] <= R[j])
                {
                    arr[k] = L[i];
                    i++;
                }
                else
                {
                    arr[k] = R[j];
                    j++;
                }
                k++;
            }

            /* Copy the remaining elements of L[], if there are any */
            while (i < n1)
            {
                arr[k] = L[i];
                i++;
                k++;
            }

            /* Copy the remaining elements of R[], if there are any */
            while (j < n2)
            {
                arr[k] = R[j];
                j++;
                k++;
            }
        }

        /* l is for left index and r is right index of the sub-array
        of arr to be sorted */
        void mergeSort(int arr[], int l, int r)
    {
        if (l < r)
        {
            int m = l+(r-l)/2; //Same as (l+r)/2, but avoids overflow for large l and h
            mergeSort(arr, l, m);
            mergeSort(arr, m+1, r);
            merge(arr, l, m, r);
        }
    }


    /* UITLITY FUNCTIONS */
    /* Function to print an array */
    void printArray(int A[], int size)
{
    int i;
    for (i=0; i < size; i++)
        printf("%d ", A[i]);
        printf("\n");
    }

    /* Driver program to test above functions */
    int main()
{
    int arr[] = {12, 11, 13, 5, 6, 7};
    int arr_size = sizeof(arr)/sizeof(arr[0]);

    printf("Given array is \n");
    printArray(arr, arr_size);

    mergeSort(arr, 0, arr_size - 1);

    printf("\nSorted array is \n");
    printArray(arr, arr_size);
    return 0;
}
