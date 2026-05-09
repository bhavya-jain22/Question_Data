
class Solution {
  public:
    vector<int> bellmanFord(int V, vector<vector<int>>& edges, int src) {
        int infi = 1e8;
        vector<int> dist(V, infi);
        dist[src] = 0;
        
        vector<vector<pair<int, int>>> adj(V, vector<pair<int, int>>());
        for(auto& edge: edges) {
            int u = edge[0];
            int v = edge[1];
            int w = edge[2];
            adj[u].push_back({v, w});
            // adj[v].push_back({u, w});
        }
        
        // Relax (V-1) times
        for(int i=0; i<V-1; i++) {
            // Relax every edge
            for(int u=0; u<V; u++) {
                if(dist[u] == infi) continue;
                for(auto& [v, w]: adj[u]) {
                    dist[v] = min(dist[v], dist[u]+w);
                }
            }
        }
        
        // check negative cycle
        bool updated = false;
        for(int u=0; u<V; u++) {
            if(dist[u] == infi) continue;
            for(auto& [v, w]: adj[u]) {
                if(dist[v]>dist[u]+w) {
                    dist[v] = dist[u]+w;
                    updated = true;
                    break;
                }
            }
        }
        
        if(updated) return {-1};
        return dist;
    }
};
