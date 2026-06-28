class Solution {
public:
    int n;
    vector<vector<pair<int, int>>> adj;
    int shortestPath(int nodes, vector<vector<int>>& edges, string labels, int k) {
        n = nodes;
        adj.resize(n);
        for(auto& edge: edges) {
            adj[edge[0]].push_back({edge[1], edge[2]});
        }

        vector<vector<int>> dp(n, vector<int>(k+1, INT_MAX));

        // {dist, node, cons}
        priority_queue<
            pair<int, pair<int, int>>,
            vector<pair<int, pair<int, int>>>,
            greater<>
        > pq;

        pq.push({0, {0, 1}});
        while(!pq.empty()) {
            auto top = pq.top();
            int d = top.first;
            int u = top.second.first;
            int cons = top.second.second;
            pq.pop();

            if(dp[u][cons]>d) dp[u][cons] = d;
            else continue;

            for(auto& edge: adj[u]) {
                auto [v, w] = edge;
                if(labels[u] == labels[v] && cons == k) continue;
                else if(labels[u] == labels[v]) pq.push({d+w, {v, cons+1}});
                else pq.push({d+w, {v, 1}});
            }
        }

        int mn = *min_element(dp[n-1].begin(), dp[n-1].end());

        return mn == INT_MAX? -1: mn;
    }
};