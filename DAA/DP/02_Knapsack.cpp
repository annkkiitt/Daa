#include <bits/stdc++.h>
using namespace std;

int knapsack(vector<int> &w,vector<int> &val,int ind,int W,vector<vector<int>> &dp){
    if(ind == 0){
        if(w[ind] <= W) return val[0];
        else return 0;
    }

    if(dp[ind][W] != -1)   return dp[ind][W];

    int notPick = 0 + knapsack(w,val,ind-1,W,dp);
    int pick = INT_MIN;

    if(w[ind] <= W){
        pick = val[ind] + knapsack(w,val,ind-1,W-w[ind],dp);
    }

    return dp[ind][W] = max(notPick,pick);

}

int main()
{
    vector<int> weight{3,2,5};
    vector<int> value{30,40,60};
    int n = weight.size();

    int w = 6;

    vector<vector<int>> dp(n,vector<int> (w+1,-1));
    cout<<knapsack(weight,value,n-1,w,dp);
    
}