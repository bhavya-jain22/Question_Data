
// https://www.geeksforgeeks.org/problems/longest-common-substring1452/1

class Solution {
    int n, m, ans = 0;
    vector<vector<int>> dp;

    int find(vector<vector<int>>& dp, const string& s1, const string& s2,
             int n, int m) {

        if(n == 0 || m == 0) return 0;

        if(dp[n][m] != -1)
            return dp[n][m];

        if(s1[n-1] == s2[m-1]) {
            dp[n][m] = 1 + find(dp, s1, s2, n-1, m-1);
            ans = max(ans, dp[n][m]);
        }
        else {
            dp[n][m] = 0;
        }

        // Explore remaining states
        find(dp, s1, s2, n-1, m);
        find(dp, s1, s2, n, m-1);

        return dp[n][m];
    }

public:
    int longCommSubstr(string& s1, string& s2) {
        n = s1.size();
        m = s2.size();

        dp.assign(n+1, vector<int>(m+1, -1));
        ans = 0;

        find(dp, s1, s2, n, m);

        return ans;
    }
};