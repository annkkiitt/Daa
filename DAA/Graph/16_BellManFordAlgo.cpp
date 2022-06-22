#include<bits/stdc++.h>
using namespace std;

struct node{
    int u;
    int v;
    int wt;
    node(int i,int j,int k){
        u= i;
        v= j;
        wt = k;
    }
};

int main(){
    int N = 6;
    vector<node> edges;
    
    edges.push_back(node(0,1,5));
	edges.push_back(node(1,2,-2));
	edges.push_back(node(1,5,-3));
	edges.push_back(node(2,4,3));
	edges.push_back(node(3,2,6));
	edges.push_back(node(3,4,-2));
	edges.push_back(node(5,3,1));

    int inf = 10000000; 
    // 21474836470
    int i = INT_MAX;
    // cout<<i;
    vector<int> dist(N,INT_MAX);

    int src=0;
    dist[src]=0;

    for(int i=1;i<=N-1;i++){
        for(auto it : edges){
            if(dist[it.u] != INT_MAX && dist[it.u]+ it.wt < dist[it.v]){
                dist[it.v] = dist[it.u]+ it.wt;
            }
        }
    }

    int flag = 0;
    for(auto it: edges){
        if(dist[it.u] + it.wt < dist[it.v]){
            flag = 1;
            break;
        }
    }

    if(flag ==0){
        for(int i=0;i<N;i++){
            cout<<i<<" "<<dist[i]<<endl;
        }
    }else{
        cout<<"Negative cycle detected";
    }
}