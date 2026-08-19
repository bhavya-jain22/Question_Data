
// https://leetcode.com/problems/shortest-common-supersequence/

class Solution {
public:
    string shortestCommonSupersequence(string s1, string s2) {
        int n = s1.size(), m = s2.size();
        vector<vector<int>> dp(n+1, vector<int>(m+1, 0));

        for(int i=1; i<=n; i++) {
            for(int j=1; j<=m; j++) {
                if(s1[i-1] == s2[j-1]) {
                    dp[i][j] = 1 + dp[i-1][j-1];
                }
                else {
                    dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
                }
            }
        }

        // no lcs
        if(dp[n][m] == 0) return s1 + s2;

        // lcs string of size of longest common subsequence
        int mx = dp[n][m];
        char lcs[mx];
        int r_s1 = 0, r_s2 = 0, l_s1 = -1, l_s2 = -1;
        int i=n, j=m, k = mx-1;

        while(i>0 && j>0) {
            if(s1[i-1] == s2[j-1]) {
                lcs[k--] = s1[i-1];
                if(r_s1 == 0) {
                    r_s1 = i-1;
                    r_s2 = j-1;
                }
                l_s1 = i-1;
                l_s2 = j-1;
                i--;
                j--;
            }
            else {
                if(dp[i-1][j] > dp[i][j-1]) i--;
                else j--;
            }            
        }

        // cout << "l_s1: " << l_s1 << "\tr_s1: "<< r_s1 << endl;
        // cout << "l_s2: " << l_s2 << "\tr_s2: " << r_s2 << endl;
        // cout << "lcs: " << lcs << endl;
        string ans;
        // insert before lcs elements
        for(int i=0; i<l_s1; i++) ans.push_back(s1[i]);
        for(int i=0; i<l_s2; i++) ans.push_back(s2[i]);

        // insert union of lcs
        i=l_s1, j=l_s2, k = 0;
        while(i <= r_s1 && j <= r_s2) {
            if(s1[i] == s2[j]) {
                ans.push_back(s1[i]);
                i++; j++; k++;
            }
            else {
                if(lcs[k] == s1[i]) {
                    ans.push_back(s2[j]);
                    j++;
                }
                else {
                    ans.push_back(s1[i]);
                    i++;
                }
            }
        }


        while(i <= r_s1) {
            ans.push_back(s1[i]);
            i++;
        }

        while(j <= r_s2) {
            ans.push_back(s2[j]);
            j++;
        }

        
        // insert remaining elements
        for(int i=r_s1+1; i<n; i++) ans.push_back(s1[i]);
        for(int i=r_s2+1; i<m; i++) ans.push_back(s2[i]);

        return ans;
    }
};