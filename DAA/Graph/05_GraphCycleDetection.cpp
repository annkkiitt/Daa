//Cycle detection using bfs
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

void addEdge(vector<int> A[],int u,int v){
    A[u].push_back(v);
    A[v].push_back(u);
}


bool cycleDetection(int i,vector<int> adj[],vector<int> &visited){
    queue<pair<int,int>> q;
    visited[i] = 1;
    q.push({i,-1});

    while(!q.empty()){
        int node = q.front().first;
        int previous = q.front().second;
        q.pop();

        for(auto it : adj[node]){
            if(!visited[it]){
                visited[it] = 1;
                q.push({it,node});
            }
            else if(it != previous){
                return true;
            }
        }
    }
    return false;
}

bool bfsCycle(vector<int> adj[],int V){
    vector<int> visited(V,0);
    for(int i=0;i<V;i++){
        if(!visited[i]){
            if(cycleDetection(i,adj,visited)) return true;
        }
    }
    return false;
}
int main()
{
    int V = 4;
	vector<int> adj[V];
	addEdge(adj, 0, 1);
	addEdge(adj, 1, 2);
	addEdge(adj, 2, 0);
	addEdge(adj, 2, 3);

    if(bfsCycle(adj,V))
        cout<<"Cycle detected";
    else 
        cout<<"Cycle not detected";
    return 0;

}