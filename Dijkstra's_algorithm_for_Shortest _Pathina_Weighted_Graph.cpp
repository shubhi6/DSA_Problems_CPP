// ..................Dijkstra's Algorithm for Shortest Path in a Weighted Graph...................

// Given a graph and a source vertex in the graph, find the shortest paths from source to all vertices in the given graph.


// Dijkstra's algorithm is a variation of the BFS algorithm. In Dijkstra's Algorithm, a SPT(shortest path tree) is generated with given source as root. 
// Each node at this SPT stores the value of the shortest path from the source vertex to the current vertex.
// We maintain two sets, one set contains vertices included in shortest path tree, other set includes vertices not yet included in shortest path tree. 
//At every step of the algorithm, we find a vertex which is in the other set (set of not yet included) and has a minimum distance from the source.


#include<bits/stdc++.h>
using namespace std;

# define INF 0x3f3f3f3f

typedef pair<int, int> iPair;

void addEdge(vector <pair<int, int> > adj[], int u, int v, int wt)
{
    adj[u].push_back(make_pair(v, wt));
    adj[v].push_back(make_pair(u, wt));
}

void shortestPath(vector<pair<int,int> > adj[], int V, int src)
{
    priority_queue< iPair, vector <iPair> , greater<iPair> > pq;
    vector<int> dist(V, INF);
    pq.push(make_pair(0, src));
    dist[src] = 0;

    while (!pq.empty())
    {
        int u = pq.top().second;
        pq.pop();

        for (auto x : adj[u])
        {
            int v = x.first;
            int weight = x.second;

            if (dist[v] > dist[u] + weight)
            {
                dist[v] = dist[u] + weight;
                pq.push(make_pair(dist[v], v));
            }
        }
    }

    printf("Vertex Distance from Source\n");
    for (int i = 0; i < V; ++i)
        printf("%d \t\t %d\n", i, dist[i]);
}

int main()
{
    int V = 9;
    vector<iPair > adj[V];
    addEdge(adj, 0, 1, 4);
    addEdge(adj, 0, 7, 8);
    addEdge(adj, 1, 2, 8);
    addEdge(adj, 1, 7, 11);
    addEdge(adj, 2, 3, 7);
    addEdge(adj, 2, 8, 2);
    addEdge(adj, 2, 5, 4);
    addEdge(adj, 3, 4, 9);
    addEdge(adj, 3, 5, 14);
    addEdge(adj, 4, 5, 10);
    addEdge(adj, 5, 6, 2);
    addEdge(adj, 6, 7, 1);
    addEdge(adj, 6, 8, 6);
    addEdge(adj, 7, 8, 7);

    shortestPath(adj, V, 0);

    return 0;
}

// Output:
 

// Vertex   Distance from Source
// 0                0
// 1                4
// 2                12
// 3                19
// 4                21
// 5                11
// 6                9
// 7                8
//8                14
