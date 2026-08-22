
// https://leetcode.com/problems/longest-subsequence-repeated-k-times/

class Solution {
public:

    bool isKRepeatedSubsequence(const string& s, const string& t, int k) {
        int n = s.size(), m = t.size();
        int repeated = 0;
        int j=0;
        for(int i=0; i<n; i++) {
            if(s[i] == t[j]) {
                j++;
                if(j==m) {
                    repeated++;
                    if(repeated == k) return true;
                    j=0;
                }
            }
        }

        return false;
    }

    string longestSubsequenceRepeatedK(string s, int k) {
        vector<int> freq(26, 0);
        for(char ch: s) freq[ch-'a']++;
        vector<char> candidate;
        for(int i=25; i>=0; i--) {
            if(freq[i] >= k) candidate.push_back('a'+i);
        }

        queue<string> q;
        for(char& ch: candidate) q.push(string(1, ch));

        string ans, curr, next;
        while(!q.empty()) {
            curr = q.front();
            q.pop();
            if(curr.size() > ans.size()) {
                ans = curr;
            }
            // generate the next candidate string
            for(char ch: candidate) {
                next = curr + ch;
                if (isKRepeatedSubsequence(s, next, k)) {
                    q.push(next);
                }
            }
        }
        return ans;
    }
};