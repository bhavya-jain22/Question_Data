
// https://leetcode.com/problems/coin-change/

class Solution {
public:
    // ---my code ---
    int coinChange(vector<int>& coins, int amount) {
        if(!amount) return 0;
        
        sort(coins.begin(), coins.end());

        int n = coins.size();
        unordered_map< int, vector<int> > dp;
        dp[0] = vector<int>(amount+2, -1);

        for(int i=0; i<n; i++) {
            dp[coins[i]] = vector<int>(amount+2, -1);
        }

        for(int i=0; i<n; i++) {
            int coin = coins[i];
            for(int j=1; j<=amount; j++) {
                if(j<coin) {
                    if(i>0) dp[coin][j] = dp[coins[i-1]][j];
                }
                else if(j==coin) dp[coin][j] = 1;
                else {
                    int notUse = (i>0) ? dp[coins[i-1]][j] : -1;
                    int use = (dp[coin][j-coin] != -1) ? dp[coin][j-coin] + 1 : -1;
                    if(use == -1) dp[coin][j] = notUse;
                    else if(notUse == -1) dp[coin][j] = use;
                    else dp[coin][j] = min(use, notUse);
                }
            }
        }

        return dp[coins[n-1]][amount];
    }


    // --- optimal solution ---

    
    // int coinChange(vector<int>& coins, int amount) {
    //     vector<int> dp(amount + 1, INT_MAX);
    //     dp[0] = 0;
    //     for(int coin : coins)
    //         for(int j = coin; j <= amount; j++)
    //             if(dp[j - coin] != INT_MAX)
    //                 dp[j] = min(dp[j], dp[j - coin] + 1);
    //     return dp[amount] == INT_MAX ? -1 : dp[amount];
    // }
};