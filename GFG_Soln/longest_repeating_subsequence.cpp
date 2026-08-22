
// https://www.geeksforgeeks.org/problems/longest-repeating-subsequence2004/1

class Solution {
  public:
    vector<vector<int>> dp;
    
    // here, memoization results in TLE because of recursion stack
    
    int find(const string& s, int n, int m) {
        if(n==0 || m==0) return 0;
        if(dp[n][m] != -1) return dp[n][m];
        if(s[n-1]==s[m-1] && n!=m) {
            return dp[n][m] = 1+find(s, n-1, m-1);
        }
        return max(find(s, n-1, m), find(s, n, m-1));
    }
    
    int find_tabulation(const string& s, int n) {
        // since the no of rows and cols are same 
        // and same return value on both of them we are initializing it in single loop
        for(int i=0; i<=n; i++) {
            dp[0][i] = 0;
            dp[i][0] = 0;
        }
        
        for(int i=1; i<=n; i++) {
            for(int j=1; j<=n; j++) {
                if(s[i-1] == s[j-1] && i!=j) dp[i][j] = 1+dp[i-1][j-1];
                else dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        }
        
        return dp[n][n];
    }
    
    int longestRepSubseq(string &s) {
        // Code here
        int n = s.size();
        dp.resize(n+1, vector<int>(n+1, -1));
        
        // return find(s, n, n);
        return find_tabulation(s, n);
        
        
    }
};