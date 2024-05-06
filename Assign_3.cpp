#include <bits/stdc++.h>
using namespace std;


vector<int> shortestPath(int V, int source, vector<vector<int>>& edges) {
    // node1 -> {node2, edgeweight}

    //igone 
    vector<pair<int, int>> adj[V + 1];
    for (auto it : edges) {
        adj[it[0]].push_back({it[1], it[2]});
        adj[it[1]].push_back({it[0], it[2]});
    }
    // storing the nodes along with distances in the form of a pair { dist, node }.
    priority_queue<pair<int, int>, vector<pair<int, int>>,
                   greater<pair<int, int>>>
        pq;

    // Create a dist array for storing the updated distances 
    // and a parent array for storing the nodes from where the current nodes
    // represented  by indices of the parent array came from.
    vector<int> dist(V + 1, INT_MAX), parent(V + 1);
    for (int i = 1; i <= V; i++)
        parent[i] = i;

    dist[source] = 0;

    // Push the source node to the queue.
    pq.push({0, source});
    while (!pq.empty()) {
        auto it = pq.top();
        pq.pop();
        int node = it.second;
        int dis = it.first;

        // Iterate through the adjacent nodes of the current popped node.
        for (auto it : adj[node]) {
            int adjNode = it.first;
            int edW = it.second;

            // Check if the previously stored distance value is
            // greater than the current computed value or not,
            // if yes then update the distance value.
            if (dis + edW < dist[adjNode]) {
                dist[adjNode] = dis + edW;
                pq.push({dis + edW, adjNode});

                // Update the parent of the adjNode to the recent
                // node where it came from.
                parent[adjNode] = node;
            }
        }
    }

    // If distance to a node could not be found, return an array containing -1.
    if (dist[V] == INT_MAX)
        return {-1};

    // Store the final path in the ‘path’ array.
    vector<int> path;
    int node = V;

    // Iterate backwards from destination to source through the parent array.
    while (parent[node] != node) {
        path.push_back(node);
        node = parent[node];
    }
    path.push_back(source);

    // Since the path stored is in a reverse order, we reverse the array
    // to get the final answer and then return the array.
    reverse(path.begin(), path.end());
    return path;
}

int main() {
    // Driver Code
    int V = 5;
    vector<vector<int>> edges = {{1, 2, 2}, {2, 5, 5}, {2, 3, 4}, {1, 4, 1}, {4, 3, 3}, {3, 5, 1}};
    vector<int> path = shortestPath(V, 1, edges);

    for (int i = 0; i < path.size(); i++) {
        cout << path[i] << " ";
    }
    cout << endl;
    return 0;
}
