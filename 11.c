#include<stdlib.h>
#include<stdio.h>
#include<time.h>
void merge(int arr[], int l, int m, int r)
{
    int i, j, k;
    int n1 = m - l + 1;
    int n2 =  r - m;

    int L[n1], R[n2];

    for (i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[m + 1+ j];
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

    while (i < n1)
    {
        arr[k] = L[i];
        i++;
        k++;
    }

    while (j < n2)
    {
        arr[k] = R[j];
        j++;
        k++;
    }
}

void mergeSort(int arr[], int l, int r)
{
    if (l < r)
    {
        int m = l+(r-l)/2;
        mergeSort(arr, l, m);
        mergeSort(arr, m+1, r);

        merge(arr, l, m, r);
    }
}

void printArray(int A[], int size)
{
    int i;
    for (i=0; i < size; i++)
        printf("%d ", A[i]);
    printf("\n");
}

int main()
{
    int i,n1,n2,sort;
    printf("Enter the number of the elements of two arrays\n");
    scanf("%d %d",&n1,&n2);
    int a1[n1],a2[n2];
    int a3[n1+n2];
    printf("Enter the elements of first unsorted array\n");
    for(i=0; i<n1; i++)
    {
        scanf("%d",&a1[i]);
        a3[i]=a1[i];
    }
    int j=i;
    printf("Enter the elements of second unsorted array\n");
    for(i=0; i<n2; i++)
    {
        scanf("%d",&a2[i]);
        a3[j]=a2[i];
        j++;
    }

    mergeSort(a3, 0, n1+n2 - 1);
    printf("Sorted array:\n");
    printArray(a3, n1+n2);

}
