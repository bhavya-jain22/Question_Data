class Solution {
public:
    string minWindow(string s, string t) {
        vector<int> sFreq(128, 0), tFreq(128, 0);
        for(auto& x: t) tFreq[x]++;
        for(auto& x: s) sFreq[x]++;
        for(int i=0; i<128; i++) {
            if(tFreq[i] && tFreq[i] > sFreq[i]) return "";
            sFreq[i] = 0;
        }

        int l = 0, r = 0, n = s.size(), left = 0, right = 0, window = INT_MAX;
        string ans = "";
        for(r; r<n; r++) {
            sFreq[s[r]]++;
            bool matched = true;
            for(int i=0; i<128 && matched; i++) if(tFreq[i] && tFreq[i] > sFreq[i]) matched = false;
            if(matched) {
                while(sFreq[s[l]] > tFreq[s[l]] && l<=r) {                    
                    sFreq[s[l]]--;
                    l++;
                }
                if(r-l+1 < window) {
                    window = r-l+1;
                    left = l;
                    right = r;
                }
                sFreq[s[l]]--;
                l++;
            }
        }
        for(int i = left; i<=right; i++) ans.push_back(s[i]);
        return ans;
    }
};