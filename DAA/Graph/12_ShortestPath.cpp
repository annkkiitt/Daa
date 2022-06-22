// Shortest path in a weighted DAG(Directed Acyclic graph)
//Birpartite Graph using bfs(kahns algo);
#include <iostream>
#include <vector>
#include <queue>
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

vector<int> topoSort(vector<int> adj[],int V){
    queue<int> q;
    vector<int> indegree(V,0);
    for(int i=0;i<V;i++){
        for(auto it: adj[i])
            indegree[it]++;
    }

    for(int i=0;i<V;i++){
        if(indegree[i]==0){
            q.push(i);
        }
    }

    vector<int> topo;
    while(!q.empty()){
        int node = q.front();
        q.pop();
        topo.push_back(node);
        for(auto it: adj[node]){
            indegree[it]--;
            if(indegree[it]==0){
                q.push(it);
            }
        }
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
    
    

}