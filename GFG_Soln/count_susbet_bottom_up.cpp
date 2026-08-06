
// https://www.geeksforgeeks.org/problems/perfect-sum-problem5633/1

class Solution {
    private:
        int ans = 0, n;
        vector<vector<int>> dp;
        
    public:    
        int perfectSum(vector<int>& arr, int target) {
            n = arr.size();
            dp.resize(n+1, vector<int>(target+1, -1));
            
            int ans = 0;
            
            for(int i=0; i<=n; i++) {
                for(int j=0; j<=target; j++) {
                    if(j==0) {
                        dp[i][j] = 1;
                        ans++;
                        continue;
                    }
                    
                    if(i==0) {
                        dp[i][j] = 0;
                        continue;
                    }
                    
                    if(arr[n-1] <= j) {
                        dp[i][j] = dp[i-1][j-arr[i-1]] + dp[i-1][j];
                    }
                    
                    else dp[i][j] = dp[i-1][j];
                    
                    if(dp[i][j] == 1) ans++;
                }
            }
            
            if(dp[n][target]==1) {
                cout << ans << endl;
            }
            else cout << 0 << endl;
        }
};