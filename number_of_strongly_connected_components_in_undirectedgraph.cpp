
//  the algorithm following the DFS traversal to find all connected components in an undirected graph:
// 1) Initialize all vertices as not visited.
// 2) Do following for every vertex 'v'.
//        (a) If 'v' is not visited before, call DFSUtil(v)
//        (b) Print new line character

// // This Function performs DFS traversal
// // of vertex v.
// DFSUtil(v)
// 1) Mark 'v' as visited.
// 2) Print 'v'
// 3) Do following for every adjacent 'u' of 'v'.
//      If 'u' is not visited, then recursively call DFSUtil(u)

#include <iostream>
#include <list>
using namespace std;

class Graph {
    int V;
    list<int>* adj;
    void DFSUtil(int v, bool visited[]);

public:
    Graph(int V);
    void addEdge(int v, int w);
    void connectedComponents();
};

void Graph::connectedComponents()
{
    bool* visited = new bool[V];
    for (int v = 0; v < V; v++)
        visited[v] = false;

    for (int v = 0; v < V; v++) {
        if (visited[v] == false) {
            DFSUtil(v, visited);
            cout << "\n";
        }
    }
}

void Graph::DFSUtil(int v, bool visited[])
{
    visited[v] = true;
    cout << v << " ";
    list<int>::iterator i;
    for (i = adj[v].begin(); i != adj[v].end(); ++i)
        if (!visited[*i])
            DFSUtil(*i, visited);
}

Graph::Graph(int V)
{
    this->V = V;
    adj = new list<int>[V];
}

void Graph::addEdge(int v, int w)
{
    adj[v].push_back(w);
    adj[w].push_back(v);
}

int main()
{
    Graph g(5);
    g.addEdge(1, 0);
    g.addEdge(1, 2);
    g.addEdge(3, 4);

    cout << "Following are connected components \n";
    g.connectedComponents();

    return 0;
}
