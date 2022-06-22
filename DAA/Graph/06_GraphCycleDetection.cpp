//Graph representation using adjacency list
#include <iostream>
#include <vector>
using namespace std;

void addEdge(vector<int> A[],int u,int v){
    A[u].push_back(v);
    A[v].push_back(u);
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

bool dfsTraversal(int node,int parent,vector<int> visited,vector<int> adj[]){
    visited[node] = 1;
    for(auto it: adj[node]){
        if(!visited[it]){
            
            if(dfsTraversal(it,node,visited,adj)) 
                return true;
        }

        else if(it != parent) return true;
    }
    return false;
}
bool dfsCycle(vector<int> adj[],int V){
    vector<int> visited(V,0);
    for(int i=0;i<V;i++){
        if(!visited[i]){
            if(dfsTraversal(i,-1,visited,adj)) return true;
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
    
    bool ans = dfsCycle(adj,V);
    if(ans) cout<<"Cycle detected";
    else cout<<"Cycle not detected";

}