#include <bits/stdc++.h>
using namespace std;


int main() {
    
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t, n;
    cin >> t;
    while (t--) {
        cin >> n;
        vector<long long> a(n), wait(n, 0);
        for(auto& x: a) cin >> x;
        long long original_ans = 0, mx = 1, benefit = 0;
        for(int i=0; i<n; i++) {
            mx = max(mx, a[i]);
            wait[i] = mx-a[i];
            original_ans += wait[i];
        }
        
        mx = 1;
        // Remember the complexity here will be O(n) and not O(n^2)
        for(int i=0; i<n; i++) {
            long long change = wait[i], curr_max = mx;
            if(a[i] > mx) {
                for(int j=i+1; j<n; j++) {
                    if(a[j] >= a[i]) break;
                    curr_max = max(curr_max, a[j]);
                    change += wait[j] - (curr_max-a[j]);
                }
            }
            benefit = max(benefit, change);
            mx = max(mx, a[i]);
        }
        
        cout << original_ans - benefit << endl;
        
    }
}