
// https://leetcode.com/problems/target-sum/

class Solution {
private:

int n;
vector<vector<int>> dp;

int utils(vector<vector<int>>& dp, vector<int>& v, int n, int target) {
    // target == 1000 (max(negative)).
    if(n==0 && target==1000) return 1;
    if(n==0) return 0;
    if(dp[n][target] != -1) return dp[n][target];
    int add = 0, sub = 0;
    if(target+v[n-1] <= 2000) add = utils(dp, v, n-1, target+v[n-1]);
    if(v[n-1] <= target) sub = utils(dp, v, n-1, target-v[n-1]);
    return dp[n][target] = add + sub;  
}

int tabulation(vector<vector<int>>& dp, vector<int>& v, int n, int target) {
    int add = 0, sub = 0;
    for(int i=0; i<=n; i++) {
        for(int j=0; j<=2000; j++) {
            if(i==0 && j==1000) {
                dp[i][j] = 1;
                continue;
            }

            if(i==0) {
                dp[i][j] = 0;
                continue;
            }

            add = sub = 0;
            if(j + v[i-1] <= 2000) {
                add = dp[i-1][j+v[i-1]];
            }
            if(v[i-1] <= j) {
                sub = dp[i-1][j-v[i-1]];
            }
            
            dp[i][j] = add + sub;            
        }
    }
    return dp[n][target];
}

public:
    int findTargetSumWays(vector<int>& nums, int target) {
        n = nums.size();
        // declared a larger size dp 
        // (because indexes can't go negative)
        // add the max(negative index) making the size -->
        // 0 <--> max(positive) + max(negative).
        dp.resize(n+1, vector<int>(2001, -1));

        // also pass the target as target + max(negative).
        
        // int ans = utils(dp, nums, n, 1000+target);
        int ans = tabulation(dp, nums, n, 1000+target);
        return ans;
    }
};