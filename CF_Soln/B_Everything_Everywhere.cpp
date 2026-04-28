/*

In a good subarray, there are only 2 distinct values: some value v and v + g, where g = gcd(v, v+g) = gcd(v, g).
Since gcd(v, v+g) = gcd(v, g), we need gcd(v, g) = g, meaning g divides v.
So the two values are v and v + g where g | v. The GCD of v and v+g is gcd(v, g) = g ✓

*/

#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t;
    cin >> t;
    
    while (t--) {
        int n;
        cin >> n;
        
        vector<int> p(n);
        for (int i = 0; i < n; i++) cin >> p[i];
        
        int count = 0;
        for (int i = 0; i < n - 1; i++) {
            int a = min(p[i], p[i+1]);
            int b = max(p[i], p[i+1]);
            int diff = b - a;
            if (a % diff == 0) count++;
        }
        
        cout << count << "\n";
    }
    
    return 0;
}