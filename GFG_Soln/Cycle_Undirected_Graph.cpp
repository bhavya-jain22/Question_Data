class Solution {
  public:
    bool isCycle(int V, vector<vector<int>>& edges) {
        // this code follows the union and find approach (my modified)
        // but this(modified) is only valid because the input is sorted,
        // if the input is online or unsorted, it will fail
        // then use proper union-find approach
        vector<int>origin(V);
        for(int i=0; i<V; i++) origin[i] = i;
        
        bool isCyclePresent = false;
        int n = edges.size();
        for(auto edge: edges) {
            int u = edge[0];
            int v = edge[1];
            if(origin[u] == origin[v]) {
                isCyclePresent = true;
                break;
            }
            else {
                origin[v] = origin[u];
            }
        }
        return isCyclePresent;
    }
};