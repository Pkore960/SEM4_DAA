#include<stdio.h>
#include <stdlib.h>
#include <time.h>

void Insertionsort(int A[],int n){
  int j,key;
   for(int i=1;i<n;i++){
       key=A[i];
       j=i-1;
       while(j>=0 && key<A[j]){
           A[j+1]=A[j];
           j--;
       }
       A[j + 1] = key;
   }
}

void Selectionsort(int A[],int n){
    int min,temp;
    for(int i=0;i<n;i++){
        min=i;
        for(int j=i;j<n;j++){
            if(A[min]>A[j]){
                  min=j;
            }
        }
        if(min!=i){
            temp=A[i];
            A[i]=A[min];
            A[min]=temp;
        }
    }
}

int main(){

    int A[100000],a,b;
    double start,end,time;

    printf("Enter 1:Insertion sort    2:Selection sort\n");
    scanf("%d",&b );

    for(int i=1;i<1000;i++){
        a=i*10;
        for(int i=0;i<a;i++){
            A[i]= rand() % 100000 +1;
        }
        start=(double)clock()/CLOCKS_PER_SEC;
        if(b==1){
            Insertionsort(A,a);
        }
        else{
            Selectionsort(A,a);
        }
        end=(double)clock()/CLOCKS_PER_SEC;
        time=end-start;
        printf("%lf\n",time);
    }

    return 0;
}
