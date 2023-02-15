#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<time.h>

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

void QuickSort(int number[25],int first,int last){
    int i, j, pivot, temp;
    if(first<last){
        pivot=first;
        i=first;
        j=last;
        while(i<j){
            while(number[i]<=number[pivot]&&i<last)
                i++;
            while(number[j]>number[pivot])
                j--;
            if(i<j){
                temp=number[i];
                number[i]=number[j];
                number[j]=temp;
            }
        }
        temp=number[pivot];
        number[pivot]=number[j];
        number[j]=temp;
        QuickSort(number,first,j-1);
        QuickSort(number,j+1,last);
    }
}

void Addnnum(int arr[],int n){
    for(int i=0;i<n;i++){
        arr[i]=rand()%10000+1;
    }
}

int main()
{
    int arr[100000],a=1,b;
    double start,end,time;

    printf("Enter 1:Merge sort    2:Quick sort\n");
    scanf("%d",&b );
    if(b==1){
        printf("Merge Sort:\n");
    }
    else{
        printf("Quick Sort:\n");
    }

    for(int i=1;i<1000;i++){
        a=i*100;
        Addnnum(arr,a);
        if(b==1){
            start=(double)clock();
            MergeSort(arr,0,a-1);
            end=(double)clock();
        }
        else{
            start=(double)clock();
            QuickSort(arr,0,a-1);
            end=(double)clock();
        }
        time=(double)((end-start)/CLOCKS_PER_SEC);
        printf("%lf\n",time);
    }

    return 0;
}
