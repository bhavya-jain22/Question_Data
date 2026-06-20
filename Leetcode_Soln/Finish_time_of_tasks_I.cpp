class Solution {
public:
    vector<vector<int>>adj;
    
    long long my_Find(int t, vector<long long>& Final, vector<int>& baseTime) {
        if(Final[t]) return Final[t];
        if(!adj[t].size()) {
            Final[t] = baseTime[t];
            return Final[t];
        }
        long long mn = LONG_LONG_MAX, mx=0;
        for(int v: adj[t]) {
            auto dur = my_Find(v, Final, baseTime);
            mn = min(mn, dur);
            mx = max(mx, dur);
        }
        
        Final[t] = mx - mn + baseTime[t] + mx;
        return Final[t];
    }
        
    long long finishTime(int n, vector<vector<int>>& edges, vector<int>& baseTime) {
        // creating adj list
        adj.resize(n);
        for(auto& edge: edges) {
            int u = edge[0], v = edge[1];
            adj[u].push_back(v);            
        }

        vector<long long> Final(n, 0);

        //solve
        my_Find(0, Final, baseTime);

        // just printing the Final time for each task
        for(auto& x: Final) cout << x << " ";
        cout << endl;

        // returning ans
        return Final[0];
    }
};