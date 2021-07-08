#include<stdio.h>
#include<time.h>
#include<stdlib.h>
void main()
{
	int i,n;
	printf("Enter number of elements : ");
	scanf("%d",&n);
    int a[n];
    for(i=0;i<n;i++)
    {
        a[i]= rand()%1000;
        printf("%d ",a[i]);
    }
    clock_t start,end;
    start=clock();
	mergesort(a,0,n-1);
    printf("\n------------------------------------");
    end=clock();
    printf("\nSorted array : ");
	for(i=0;i<n;i++)
	printf("%d ",a[i]);
    printf("\ntime taken to sort %d numbers is %fsecs",n,(((double)(end-start))/(CLOCKS_PER_SEC)));
}
void mergesort(int a[], int low, int high)
{
    int mid;
    if(low<high)
    {
        mid=(low+high)/2;
        mergesort(a,low,mid);
        mergesort(a,mid+1,high);
        merge(a,low,mid,high);
    }
}
void merge(int a[],int low, int mid, int high)
{
    int i,j,k,c[100];
    i=low;
    k=low;
    j=mid+1;
    while(i<=mid && j<=high)
    {
        if (a[i]<a[j])
            c[k++]=a[i++];
        else
            c[k++]=a[j++];
    }
    while(i<=mid)
        c[k++]=a[i++];
    while(j<=high)
        c[k++]=a[j++];
    for(i=low;i<=high;i++)
    a[i]=c[i];
}
