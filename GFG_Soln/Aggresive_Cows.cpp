#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int aggressiveCows(vector<int> &stalls, int k) {
        set<int>s;
        int n = stalls.size();
        for(int i=0; i<n; i++) s.insert(stalls[i]);
        
        int mn = *(s.begin());
        auto it = s.end();
        advance(it, -1);
        int mx = *it;
        
        int ans = 0;
        
        int low = 1, high = mx-mn;
        
        while(low<=high) {
            int mid = low + (high-low)/2;
            int cur = mn, seated = 1;
            // cout << "mid: " << mid;
            for(int i=0; i<k; i++) {
                cur += mid;
                auto it = s.lower_bound(cur);
                if(it != s.end()) {
                    cur = *it;
                    seated++;
                }
                else break;
            }
            // cout << "\t\tseated: " << seated << endl;
            if(seated < k) high = mid-1;
            else {
                ans = mid;
                low = mid+1;
            }
        }
        
        // cout << low << endl;
        return ans;
    }
};