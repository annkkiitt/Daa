#include <iostream>
using namespace std;

int binarySearch(int A[],int l,int r,int key){
    if(r>=l){
        int mid = l+(r-l)/2;

        if(A[mid] == key){
            return 1;
        }
        if(A[mid]<key){
            return binarySearch(A,mid+1,r,key);
        }
        else{
            return binarySearch(A,l,mid-1,key);
        }
    }
    return -1;
}
int main()
{
    int A[8] = {1,4,10,28,48,178,200,900};

    if(binarySearch(A,0,4,400) == -1){
        cout<<"Element not found";
    }
    else{
        cout<<"ELment found";
    }
}
