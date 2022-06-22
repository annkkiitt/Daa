#include <bits/stdc++.h>
using namespace std;

int lcs(string &s1,string &s2,int ind1,int ind2,vector<vector<int>> &dp){
    if(ind1<0 || ind2<0)    return 0;

    if(dp[ind1][ind2] != -1)    return dp[ind1][ind2];
    if(s1[ind1]==s2[ind2])  return 1+lcs(s1,s2,ind1-1,ind2-1,dp);

    return dp[ind1][ind2] = max(lcs(s1,s2,ind1-1,ind2,dp),lcs(s1,s2,ind1,ind2-1,dp));
}
int main()
{
    string s1 = "acde";
    string s2 = "madfeg";
    int ind1 = s1.length()-1;
    int ind2 = s2.length()-1;

    vector<vector<int>> dp(ind1+1,vector<int> (ind2+1,-1));
    cout<<lcs(s1,s2,ind1,ind2,dp);
}