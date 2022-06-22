// C++ program to detect cycle
// in an undirected graph
// using BFS.
#include <bits/stdc++.h>
using namespace std;

void addEdge(vector<int> adj[], int u, int v)
{
	adj[u].push_back(v);
	adj[v].push_back(u);
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
        if(!visited[i] && cycleDetection(i,adj,visited))
            return true;
    }
    return false;
}

// Driver program to test methods of graph class
int main()
{
	int V = 4;
	vector<int> adj[V];
	addEdge(adj, 0, 1);
	addEdge(adj, 1, 2);
	// addEdge(adj, 2, 0);
	addEdge(adj, 2, 3);

	if (bfsCycle(adj, V))
		cout << "Yes";
	else
		cout << "No";

	return 0;
}
