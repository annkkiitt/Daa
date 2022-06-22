#include <iostream>
#include <vector>
#include <queue>
#include <climits>
using namespace std;

void addEdge(vector<pair<int,int>> A[],int u,int v,int w){
    A[u].push_back(make_pair(v,w));
    A[v].push_back(make_pair(u,w));
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

void dijkstra(vector<pair<int,int>> adj[],int source,int V){
    priority_queue<pair<int,int>,vector<pair<int,int> >,greater<pair<int,int>> > pq; // for priority min heap queue
    vector<int> dist(V,INT_MAX);
    dist[source]=0;
    pq.push(make_pair(0,source));

    while(!pq.empty()){
        int distance = pq.top().first;
        int prev = pq.top().second;

        pq.pop();
        for(auto it : adj[prev]){
            int next = it.first;
            int nextDist = it.second;

            if(distance + nextDist < dist[next]){
                dist[next] = distance + nextDist;
                pq.push(make_pair(dist[next],next));
            }
        }
    }

    for(int i=1;i<V;i++){
        cout<<dist[i]<<" ";
    }

}
int main()
{
    int V = 6;
	vector<pair<int,int>> adj[V];
    addEdge(adj,1,2,2);
    addEdge(adj,1,4,1);
    addEdge(adj,4,3,3);
    addEdge(adj,2,3,4);
    addEdge(adj,3,5,1);
    addEdge(adj,2,5,5);
    
    dijkstra(adj,1,V);

}