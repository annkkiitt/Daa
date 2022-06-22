#include <bits/stdc++.h>
using namespace std;

int fibo(int n,vector<int> &dp){
    dp[0] = 0;
    dp[1] = 1;

    for(int i=0;i<=n;i++){
        dp[n] = dp[n-1] + dp[n+2];
    }  
    return dp[n]; 
}

int main()
{
    int n;
    cout<<"Enter the number : ";
    cin>>n;
    vector<int> dp(n+1,-1);
    

    cout<<fibo(n,dp);
}