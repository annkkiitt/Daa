#include <iostream>
using namespace std;

void insertionSort(int A[],int n){
    int i,j,flag=0,temp;
    for(i=1;i<n;i++){
        temp = A[i];
        j=i-1;
        while(j >=0 && temp < A[j]){
            A[j+1] = A[j];
            j--;
        }
        A[j+1] = temp;
    }
}

int main()
{
    int n;
    cout<<"Enter the number of elements: ";
    cin>>n;
    int A[n];
    cout<<"Enter the elements of array: "<<endl;
    for(int i=0;i<n;i++){
        cin>>A[i];
    }

    insertionSort(A,n);

    cout<<"After sorting: "<<endl;
    for(int i=0;i<n;i++){
        cout<<A[i]<<" ";
    }

}