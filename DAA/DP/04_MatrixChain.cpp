#include <bits/stdc++.h>
using namespace std;

int matrix(int i,int j,int A[],vector<vector<int>> &dp){
    if(i==j)    return 0;
    if(dp[i][j] != -1) return dp[i][j];

    int steps;
    int min = INT_MAX;
    for(int k=i;k<j;k++){
        steps = A[i-1]*A[k]*A[j] + matrix(i,k,A,dp)+matrix(k+1,j,A,dp);
        if(steps<min)   min = steps;
    }
    return dp[i][j] = min;
}
int main()
{
    int A[] = {10,20,30,40,50};
    int n = 5;
    vector<vector<int>> dp(n,vector<int> (n,-1));
    cout<<matrix(1,n-1,A,dp);

}