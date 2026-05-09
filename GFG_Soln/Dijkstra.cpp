class Solution {
  public:
    vector<int> dijkstra(int V, vector<vector<int>> &edges, int src) {

        vector<int> dist(V, INT_MAX);
        vector<bool> vis(V, false);
        
        // adj[u] = {v, w}
        vector<vector<pair<int, int>>> adj(V, vector<pair<int, int>>());
        // constructing adj list
        for(auto& edge: edges) {
            int u = edge[0];
            int v = edge[1];
            int w = edge[2];
            adj[u].push_back({v, w});
            adj[v].push_back({u, w});
        }
        
        // min heap ->
        // {weight, node}
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
        
        pq.push({0, src});
        
        while(!pq.empty()) {
            auto [wt, node] = pq.top();
            pq.pop();
            
            if(vis[node]) continue;
            
            vis[node] = true;
            dist[node] = wt;
            for(auto& [v, d] : adj[node]) {
                if(!vis[v]) pq.push({wt+d, v});
            }
        }
        return dist;
    }
};