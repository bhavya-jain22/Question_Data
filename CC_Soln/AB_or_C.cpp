#include <bits/stdc++.h>
using namespace std;

int main() {
    
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t, n, a, b, c;
    cin >> t;
    while (t--) {
        cin >> n;
        vector<vector<int>> arr(n);
        // (val, index)
        multiset<pair<int, int>> ms;
        
        for(int i=0; i<n; i++) {
            cin >> a >> b >> c;
            arr[i] = {a, b, c};
            sort(arr[i].begin(), arr[i].end());
            ms.insert({arr[i][2], i});
        }
        
        // initially assume that we are taking the max element of each (a,b,c)
        vector<int> cur_pos(n, 2);
        
        
        int ans = INT_MAX, mn, mx;
        
        while(1) {
            auto min_it = ms.begin();
            auto max_it = ms.end();
            advance(max_it, -1);
            
            mn = min_it->first;
            mx = max_it->first;
            
            ans = min(ans, mx-mn);
            
            // get the index of the max element in arr
            auto max_ind = max_it->second;
            
            // if no smaller elements present at the arr[max_ind], break
            if(cur_pos[max_ind] == 0) break;
            
            // erase the prev max, and insert the smaller element from arr[max_ind]
            ms.erase(max_it);
            cur_pos[max_ind]--;
            
            ms.insert({arr[max_ind][cur_pos[max_ind]], max_ind});
            
        }
        
        cout << ans << endl;
    }
}