//Birpartite Graph using dfs
#include <iostream>
#include <vector>
#include <stack>
using namespace std;

void addEdge(vector<int> A[],int u,int v){
    A[u].push_back(v);
}

void printGraph(vector<int> A[],int V){
    for(int i=0;i<V;i++){
        // cout<<"Adjacency list of Vertex: "<<i<<endl;
        cout<<i<<"(Head)";
        for(auto j:A[i]){
            cout<<" -->"<<j;
        }
        cout<<endl;
        cout<<endl;
    }
}

void findTopo(int node,vector<int> adj[],int V,stack<int> &s,vector<int> &visited){
    visited[node] = 1;

    for(auto it : adj[node]){
        if(!visited[it]){
            findTopo(it,adj,V,s,visited);
        }
    }
    s.push(node); 
}
vector<int> topoSort(vector<int> adj[],int V){
    stack<int> s;
    vector<int> visited(V,0);
    for(int i=0;i<V;i++){
        if(!visited[i]){
            findTopo(i,adj,V,s,visited);
        }
    }
    vector<int> topo;
    while(!s.empty()){
        topo.push_back(s.top());
        cout<<s.top()<<" ";
        s.pop();
    }
    return topo;

}
int main()
{
    int V = 6;
	vector<int> adj[V];
    addEdge(adj,5, 2);
    addEdge(adj,5, 0);
    addEdge(adj,4, 0);
    addEdge(adj,4, 1);
    addEdge(adj,2, 3);
    addEdge(adj,3, 1);
    
    vector<int> topo = topoSort(adj,V);

    // for(int i=V-1;i>=0;i--){
    //     cout<<topo[i]<<" ";
    // }

}