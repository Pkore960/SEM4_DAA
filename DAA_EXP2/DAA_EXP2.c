#include<stdio.h>
#include<stdlib.h>
#include<math.h>

void Printarr(int arr[],int n)
{
    for(int i=0; i<n; i++)
    {
        printf("%d ",arr[i]);
    }
    printf("\n");
}

void Merge(int arr[],int p,int q,int r)
{
    int n1,n2;
    n1=q-p+1;
    n2=r-q;
    int L[n1+1], R[n2+1];
    for(int i=0; i<n1; i++)
    {
        L[i]=arr[p+i];
    }
    for(int i=0; i<n2; i++)
    {
        R[i]=arr[q+i+1];
    }
    L[n1]=99999;
    R[n2]=99999;

    int i=0,j=0;
    for(int k = p ; k <= r ; k++)
    {
        if(L[i] <= R[j])
        {
            arr[k] = L[i];
            i++;
        }
        else
        {
            arr[k] = R[j];
            j++;
        }
    }
    return;
}

void MergeSort(int arr[],int p,int r)
{
    int q;
    if(r>p)
    {
        int q = (p+r)/2;
        MergeSort(arr,p,q);
        MergeSort(arr,q+1,r);
        Merge(arr,p,q,r);
    }
    return;
}

int main()
{
    int n;
    printf("Enter the no. of elements in the array:");
    scanf("%d",&n);
    int arr[n];
    printf("Enter elements in array:\n");
    for(int i=0; i<n; i++)
    {
        scanf("%d",&arr[i]);
    }

    MergeSort(arr,0,n-1);

    printf("\nSorted array is:\n");
    Printarr(arr,n);

    return 0;
}
