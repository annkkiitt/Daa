#include <iostream>
using namespace std;

void merge(int A[],int low,int mid,int high){
    int n1=mid-low+1;
    int n2=high-mid;
    int A1[n1],A2[n2];

    for(int i=0;i<n1;i++){
        A1[i] = A[low+i];
    }

    for(int i=0;i<n2;i++){
        A2[i] = A[mid+1+i];
    }
    
    int i=0,j=0;
    int k=low;

    while(i<n1 && j<n2){
        if(A1[i]<=A2[j]){
            A[k++] = A1[i++];
        }
        else{
            A[k++]=A1[j++];
        }
    }

    while(i<n1){
        A[k++]=A1[i++];
    }
    while(j<n2){
        A[k++]=A2[j++];
    }

}

void mergeSort(int A[],int low,int high){
    if(low<high){
        int mid=low+(high-low)/2;
        mergeSort(A,low,mid);
        mergeSort(A,mid+1,high);
        merge(A,low,mid,high);
    }
}
int main()
{
    int A[] = {19,29,38,48,78,9};
    auto arr_size = sizeof(A) / sizeof(A[0]);
    mergeSort(A,0,arr_size-1);

    cout<<"Sorted array is"<<endl;
    for(int i=0;i<arr_size;i++){
        cout<<A[i]<<" ";
    }
  
}