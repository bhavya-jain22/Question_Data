class Solution {
public:

    bool isRotten(vector<vector<int>>& grid) {
        bool allRotten = true;
        for(int i=0; i<grid.size(); i++) {
            for(int j=0; j<grid[0].size(); j++) {
                if(grid[i][j] == 1) {
                    allRotten = false;
                    break;
                }
            }
        }
        return allRotten;
    }

    int orangesRotting(vector<vector<int>>& grid) {
        int ans = 0, n = grid.size(), m = grid[0].size();
        queue<pair<int, int>> q;

        for(int i=0; i<n; i++) {
            for(int j=0; j<m; j++) {
                if(grid[i][j] == 2) {
                    q.push({i, j});
                }
            }
        }
        
        while(!q.empty() && !isRotten(grid)) {
            ans++;
            int times = q.size();
            for(int rot = 0; rot<times; rot++) {
                auto [i, j] = q.front();
                q.pop();
                if(i>0 && grid[i-1][j] == 1) {
                    q.push({i-1, j});
                    grid[i-1][j] = 2;
                }
                if(i<grid.size()-1 && grid[i+1][j] == 1) {
                    q.push({i+1, j});
                    grid[i+1][j] = 2;
                }
                if(j>0 && grid[i][j-1] == 1) {
                    q.push({i, j-1});
                    grid[i][j-1] = 2;
                }
                if(j<grid[0].size()-1 && grid[i][j+1] == 1) {
                    q.push({i, j+1});
                    grid[i][j+1] = 2;
                }

            }
            // cout << ans << endl;
            // for(int i=0; i<grid.size(); i++) {
            //     for(int j=0; j<grid[0].size(); j++) {
            //         cout << grid[i][j] << " ";
            //     }
            //     cout << endl;
            // }
            // cout << endl;
        }

        if(isRotten(grid)) return ans;
        return -1;
        

    }
};