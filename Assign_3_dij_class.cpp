#include <iostream>
#include <vector>
#include <queue>
#include <limits>

using namespace std;
class Graph
{
    int V;
    vector<vector<pair<int,int>>>adj;
    public:
    Graph(int n)
    {
        V=n;
        adj.resize(n);
    }
    void addEdge(int u,int v,int w)
    {
        adj[u].push_back({v,w});
        adj[v].push_back({u,w});
    }
    vector<int>dijekstra(int source)
    {
        vector<int>d(V,INT_MAX);
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        pq.push({0,source});
        d[source]=0;
        while(!pq.empty())
        {
            int u=pq.top().second;
            pq.pop();
            for(auto i:adj[u])
            {
                int v=i.first;
                int w=i.second;
                if(d[u]+w<d[v])
                {
                    d[v]=d[u]+w;
                    pq.push({d[v],v});
                }
            }

        }
        return d;
    }

};
int main()
{
    int n = 6; // Number of vertices in the graph
    Graph graph(n);

    // Adding edges and weights to the graph
    graph.addEdge(0, 1, 4);
    graph.addEdge(0, 2, 1);
    graph.addEdge(1, 2, 2);
    graph.addEdge(1, 3, 5);
    graph.addEdge(2, 3, 2);
    graph.addEdge(2, 4, 1);
    graph.addEdge(3, 4, 3);
    graph.addEdge(4, 5, 2);
    int source = 0;
    vector<int>dist=graph.dijekstra(source);
    cout<<"distances from start point:distance"<<endl;
    for(int i=0;i<n;i++)
    { 
        cout<<i<<":"<<dist[i]<<endl;
    }
    return 0;
}