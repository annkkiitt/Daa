//Birpartite Graph using dfs
#include <iostream>
#include <vector>
#include <queue>
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

bool bipartite(int src,vector<int> color,vector<int> adj[],int V){
    queue<int> q;
    q.push(src);
    color[src] = 1;

    while(!q.empty()){
        int node = q.front();
        q.pop();

        for(auto it: adj[node]){
            if(color[it] == -1){
                color[it] = 1-color[node];
                q.push(it);
            }
            else if(color[it] == color[node]){
                return false;
            }
        }
    }
    return true;
}
bool bipartiteGraph(vector<int> adj[],int V){
    vector<int> color(V,-1);
    for(int i=0;i<V;i++){
        if(color[i]==-1){
            if(!bipartite(i,color,adj,V)){
                return false;
            }
        }
    }
    return true;

}
int main()
{
    int V = 5;
	vector<int> adj[V];
	addEdge(adj, 0, 3);
	addEdge(adj, 0, 1);
	addEdge(adj, 3, 2);
	addEdge(adj, 2, 1);
    
    bool ans = bipartiteGraph(adj,V);
    if(ans) cout<<"bipartite detected";
    else cout<<"bipartite not detected";

}