#include <iostream>
#include <string.h>
using namespace std;

int main()
{
    int min;
    string name[8] = {"Ankit","Aman","Anuj1","Zero","Xye","Anuj","Agastya","Badri"};
    for(int i=0;i<7;i++){
        min=i;
        for(int j=i+1;j<8;j++){
            if(name[j]<name[min]){
                min=j;
            }
        }
        swap(name[i],name[min]);
    }

    for(int i=0;i<8;i++){
        cout<<name[i]<<" ";
    }
}