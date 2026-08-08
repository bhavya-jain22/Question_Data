
// https://leetcode.com/problems/coin-change/

class Solution {
private:

int utils(vector<vector<int>>& dp, vector<int>& coins, int n, int amount) {
    if(amount == 0) return 0;
    // special return for base case;
    if(n==0) return -3;
    if(dp[n][amount] != -1) return dp[n][amount];
    if(coins[n-1] <= amount) {
        int take = 1 + utils(dp, coins, n, amount-coins[n-1]);
        int not_take = utils(dp, coins, n-1, amount);
        if(take > 0 && not_take>0) {
            return dp[n][amount] =  min(take, not_take);
        }
        else if(take>0) {
            return dp[n][amount] = take;
        }
        else return dp[n][amount] = not_take;
    }
    return dp[n][amount] = utils(dp, coins, n-1, amount);
}

int tabulation(vector<vector<int>>& dp, vector<int>& coins, int n, int amount) {
    // lower priority base case first;
    // if(i==0) ->
    for(int j=0; j<=amount; j++) dp[0][j] = -3;
    // higher priority base case later;
    // if(j==0) ->
    for(int i=0; i<=n; i++) dp[i][0] = 0;

    int take = 0, not_take = 0;
    for(int i=1; i<=n; i++) {
        for(int j=1; j<=amount; j++) {
            take = 0, not_take = 0;
            if(coins[i-1] <= j) {
                take = 1+dp[i][j-coins[i-1]];
            }
            not_take = dp[i-1][j];

            if(take > 0 && not_take>0) dp[i][j] =  min(take, not_take);
            else if(take>0) dp[i][j] = take;
            else dp[i][j] = not_take;
        }
    }
    return dp[n][amount];
}

public:
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        vector<vector<int>> dp(n+1, vector<int>(amount+1, -1));
        // int ans = utils(dp, coins, n, amount);
        int ans = tabulation(dp, coins, n, amount);
        return ans<0? -1: ans;
    }
};