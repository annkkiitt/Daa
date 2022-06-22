//Graph representation using adjacency list
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

vector<int> bfsTraversal(int V,vector<int> A[]){
    vector<int> bfs;
    vector<int> visited(V,0);

    for(int i=0;i<V;i++){
        if(!visited[i]){
            queue<int> q;
            q.push(i);
            visited[i] = 1;

            while(!q.empty()){
                int node = q.front();
                q.pop();
                bfs.push_back(node);

                for(auto it : A[node]){
                    if(!visited[node]){
                        q.push(it);
                        visited[it] =1;
                    }
                }
            }


        }
    }
    return bfs;
}

int main()
{
    int V=7; //No. of vertices
    vector<int> adj[V];
    addEdge(adj, 0, 1);
    addEdge(adj, 0, 4);
    addEdge(adj, 1, 2);
    addEdge(adj, 1, 3);
    addEdge(adj, 1, 4);
    addEdge(adj, 2, 3);
    addEdge(adj, 3, 4);

    addEdge(adj,5,6);
    
    printGraph(adj, V);
    cout<<endl;
    vector<int> bfs = bfsTraversal(V,adj);
    for(int i=0;i<V;i++){
        cout<<bfs[i]<<" ";
    }
    return 0;
}