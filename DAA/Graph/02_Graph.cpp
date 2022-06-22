//Graph representation using adjacency list
#include <iostream>
#include <vector>
using namespace std;

void addEdge(vector<pair<int,int>> A[],int u,int v,int w){
    A[u].push_back(make_pair(v,w));
    A[v].push_back(make_pair(u,w));
}

void printGraph(vector<pair<int,int>> A[],int V){
    for(int i=0;i<V;i++){
        // cout<<"Adjacency list of Vertex: "<<i<<endl;
        cout<<i<<"(Head)";
        for(auto j:A[i]){
            cout<<"--("<<j.second<<")-->"<<j.first;
        }
        cout<<endl;
        cout<<endl;
    }
}

int main()
{
    int V=5; //No. of vertices
    vector<pair<int,int>> adj[V];
    addEdge(adj, 0, 1,2);
    addEdge(adj, 0, 4,3);
    addEdge(adj, 1, 2,2);
    addEdge(adj, 1, 3,4);
    addEdge(adj, 1, 4,2);
    addEdge(adj, 2, 3,5);
    addEdge(adj, 3, 4,5);
    printGraph(adj, V);
    return 0;

}