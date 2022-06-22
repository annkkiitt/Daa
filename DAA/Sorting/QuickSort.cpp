#include <iostream>
using namespace std;

int partion(int A[],int low,int high){
    int pivot = A[low];
    int i=low;
    int j=high;

    while(i<j){
        do{
            i++;
        }while(A[i]<=pivot);

        while(A[j]>pivot){
            j--;
        }

        if(i<j){
            swap(A[i],A[j]);
        }
    }
    swap(A[low],A[j]);
    return j;
}

void quickSort(int A[],int low,int high){
    if(low<high){
        int j=partion(A,low,high);
        quickSort(A,low,j);
        quickSort(A,j+1,high);
    }
}


int main()
{
    int A[] = {2,30,34,1,8,20,7,4,0,100,0};
    quickSort(A,0,10);
    for(int i=0;i<11;i++){
        cout<<A[i]<<" ";
    }
}