......................Kosaraju's algorithm............................
    
Following is detailed Kosaraju's algorithm.

1.Create an empty stack 'S' and do DFS traversal of a graph. In DFS traversal, after calling recursive DFS for adjacent vertices of a vertex, 
push the vertex to stack. In the above graph, if we start DFS from vertex 0, we get vertices in the stack as 1, 2, 4, 3, 0.
    
2.Reverse directions of all arcs to obtain the transpose graph.
    
3.One by one pop a vertex from S while S is not empty. Let the popped vertex be 'v'. Take v as source and do DFS (call DFSUtil(v)).
The DFS starting from v prints strongly connected component of v. In the above example, we process vertices in order 0, 3, 4, 2, 1 (One by one popped from stack).


#include <iostream>
#include <list>
#include <stack>
using namespace std;

class Graph
{
    int V;
    list<int> *adj;

    void fillOrder(int v, bool visited[], stack<int> &Stack);
    void DFSUtil(int v, bool visited[]);

public:
    Graph(int V);
    void addEdge(int v, int w);
    void printSCCs();
    Graph getTranspose();
};

Graph::Graph(int V)
{
    this->V = V;
    adj = new list<int>[V];
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

Graph Graph::getTranspose()
{
    Graph g(V);
    for (int v = 0; v < V; v++)
    {
        list<int>::iterator i;
        for(i = adj[v].begin(); i != adj[v].end(); ++i)
        {
            g.adj[*i].push_back(v);
        }
    }
    return g;
}

void Graph::addEdge(int v, int w)
{
    adj[v].push_back(w);
}

void Graph::fillOrder(int v, bool visited[], stack<int> &Stack)
{
    visited[v] = true;
    list<int>::iterator i;
    for(i = adj[v].begin(); i != adj[v].end(); ++i)
        if(!visited[*i])
            fillOrder(*i, visited, Stack);
    Stack.push(v);
}

void Graph::printSCCs()
{
    stack<int> Stack;
    bool *visited = new bool[V];
    for(int i = 0; i < V; i++)
        visited[i] = false;
    for(int i = 0; i < V; i++)
        if(visited[i] == false)
            fillOrder(i, visited, Stack);
    Graph gr = getTranspose();
    for(int i = 0; i < V; i++)
        visited[i] = false;
    while (Stack.empty() == false)
    {
        int v = Stack.top();
        Stack.pop();
        if (visited[v] == false)
        {
            gr.DFSUtil(v, visited);
            cout << endl;
        }
    }
}

int main()
{
    Graph g(5);
    g.addEdge(1, 0);
    g.addEdge(0, 2);
    g.addEdge(2, 1);
    g.addEdge(0, 3);
    g.addEdge(3, 4);
    cout << "Following are strongly connected components in "
            "given graph \n";
    g.printSCCs();
    return 0;
}
_
