//DFS traversal
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

void addEdge(vector<int> A[],int u,int v){
    A[u].push_back(v);
    A[v].push_back(u);
}

void printGraph(vector<int> A[],int V){
    for(int i=1;i<=V;i++){
        // cout<<"Adjacency list of Vertex: "<<i<<endl;
        cout<<i<<"(Head)";
        for(auto j:A[i]){
            cout<<" -->"<<j;
        }
        cout<<endl;
        cout<<endl;
    }
}

void dfs(int node,vector<int> &visited,vector<int> adj[],vector<int> &storeDfs){
    storeDfs.push_back(node);
    visited[node] = 1;
    for(auto it : adj[node]){
        if(!visited[it])
            dfs(it,visited,adj,storeDfs);
    }
}

vector<int> dfsTraversal(int V,vector<int> adj[]){
    vector<int> visited(V,0);
    vector<int> storeDfs;
    for(int i=1;i<=V;i++){
        if(!visited[i]){
           dfs(i,visited,adj,storeDfs); 
        }
    }
    return storeDfs;
}

int main()
{
    int V=8; //No. of vertices
    vector<int> adj[V];
    addEdge(adj, 1, 2);
    addEdge(adj, 2, 4);
    addEdge(adj, 2, 7);
    addEdge(adj, 4, 6);
    addEdge(adj, 7, 6);

    addEdge(adj, 3, 5);
    
    vector<int> dfs = dfsTraversal(V,adj);
    for(int i=0;i<V-1;i++){
        cout<<dfs[i]<<" ";
    }
    return 0;
}