#include<bits/stdc++.h>
using namespace std;

class Graph {
    int V; 
    vector<vector<int>> adj; 

public:
    Graph(int V) {
        this->V=V;
        adj.resize(V); 
    }

    void addEdge(int u, int v) {
        adj[u].push_back(v);
        adj[v].push_back(u); 
    }

    void DFSUtil(int v, vector<bool>& visited) {
        visited[v] = true;
        cout << v << " ";

        for (int i : adj[v]) {
            if (!visited[i]) {
                DFSUtil(i, visited);
            }
        }
    }

    void DFS(int v) {
        vector<bool> visited(V, false);
        cout << "Depth First Search (DFS) starting from vertex " << v << ": "<<endl;
        DFSUtil(v, visited);
        cout << endl;
    }

    void BFS(int v) {
        vector<bool> visited(V, false);
        queue<int> q;

        visited[v] = true;
        q.push(v);

        cout << "Breadth First Search (BFS) starting from vertex " << v << ": "<<endl;

        while (!q.empty()) {
            v = q.front();
            cout << v << " ";
            q.pop();

            for (int i : adj[v]) {
                if (!visited[i]) {
                    visited[i] = true;
                    q.push(i);
                }
            }
        }
        cout << endl;
    }
    // Function to find the level of a node in the graph
    int findNodeLevel(int X) {
        vector<bool> visited(V, false);
        vector<int> level(V, 0); 
        queue<int> q;

        q.push(0); 
        visited[0] = true; 

        while (!q.empty()) {
            int node = q.front();
            q.pop();

            for (int i : adj[node]) {
                if (!visited[i]) {
                    visited[i] = true;
                    //level of adj node  = level of node + 1
                    level[i] = level[node] + 1; // Increment level from the current node
                    q.push(i);
                }
            }
        }

        if (X >= 0 && X < V)
            return (visited[X]) ? level[X] : -1;
        else 
            return -1;
    }
};

int main() {
    int V = 6; 

    Graph g(V);

    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 3);
    g.addEdge(1, 4);
    g.addEdge(2, 4);
    g.addEdge(3, 4);
    g.addEdge(3, 5);
    g.addEdge(4, 5);

    g.DFS(1);
    g.BFS(3);
    int node = 5; // Example node to find the level of
    int level = g.findNodeLevel(node);
    if (level != -1)
        cout << "Level of node " << node << " is: " << level << endl;
    else
        cout << "Node " << node << " is not in the graph." << endl;
    return 0;
}