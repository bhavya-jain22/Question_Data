
// https://leetcode.com/contest/weekly-contest-517/problems/minimum-operations-to-form-subset-sum-i/

class Solution {
public:
    vector<vector<int>> dp;

    int utils(vector<int>& nums, int n, int sum) {
        if(sum==0) return 0;
        if(n==0) return INT_MAX;
        if(dp[n][sum] != -1) return dp[n][sum];
        
        // Don't take nums[n-1]
        long long ans = utils(nums, n-1, sum);

        // Multiplication: x, 2x, 4x, ...
        int x = nums[n-1], cost = 0;        
        while(x<=sum) {
            ans = min(ans, 0LL+cost+utils(nums, n-1, sum-x));
            cost++;
            x *= 2;
        }

        // Division: x/2, x/4, x/8, ...
        x = nums[n-1], cost = 0;
        while(x>0) {
            cost++;
            x /= 2;            
            if(x<=sum) ans = min(ans, 0LL+cost+utils(nums, n-1, sum-x));
        }

        return dp[n][sum] = ans;
    }
    int minOperations(vector<int>& nums, int sum) {
        int n = nums.size();
        dp.assign(n+1, vector<int>(sum+1, -1));
        return utils(nums, n, sum)==INT_MAX? -1: dp[n][sum];
    }
};