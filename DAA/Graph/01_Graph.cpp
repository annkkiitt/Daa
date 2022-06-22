//Graph representation using adjacency matrix

#include <iostream>
using namespace std;

int main()
{
    int n; //No. of vertices
    int m;  //No. of edges
    cout<<"Enter the no. of vertices and edges: ";
    cin>>n>>m;

    int Adj[n+1][n+1] = {{0,0}};
    for(int i=0;i<m;i++){
        int u,v;
        cout<<"Enter the path: ";
        cin>>u>>v;
        Adj[u][v]=1;
        Adj[v][u]=1;
    }
    
}