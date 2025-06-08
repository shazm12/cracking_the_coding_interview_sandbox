#include <bits/stdc++.h>
using namespace std;
vector<vector<vector<int>>> constructAdj(vector<vector<int>>& edges, int V) {

    vector<vector<vector<int>>> adj(V);

    for (const auto& edge : edges) {
        int u = edge[0];    // source node
        int v = edge[1];    // destination node
        int weight = edge[2]; // weight 
        
        adj[u].push_back({v, weight});
        
    }
    
    return adj;
}


vector<int> dijkstra(int V, vector<vector<int>> &edges, int src){ 
    vector<vector<vector<int>>> adj = constructAdj(edges, V);
    priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;
    vector<int> dist(V, INT_MAX);
    pq.push({0,src});
    dist[src] = 0;
    while(!pq.empty()) {
        int u = pq.top()[1];
        pq.pop();
        
        for(auto x: adj[u]){
            int v = x[0];
            int weight = x[1];
            if(dist[u] + weight < dist[v]) {
                dist[v] = dist[u] + weight;
                pq.push({dist[v], v});
            }
        }
        
    }
    return dist;
}

int main() {
    // Sample graph initialization
    int V = 5;  
    int src = 0; 

    // Edges in format {u, v, weight}
    vector<vector<int>> edges = {
        {0, 1, 4},  
        {0, 2, 1},  
        {2, 1, 2},  
        {2, 3, 5},  
        {1, 3, 1},  
        {3, 4, 3}   
    };

    vector<int> distances = dijkstra(V, edges, src);

    cout << "Shortest distances from node " << src << ":\n";
    for (int i = 0; i < V; ++i) {
        if (distances[i] == INT_MAX) {
            cout << "Node " << i << ": Not reachable\n";
        } else {
            cout << "Node " << i << ": " << distances[i] << "\n";
        }
    }

    return 0;
}
