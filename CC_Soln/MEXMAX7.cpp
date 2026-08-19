
// https://www.codechef.com/problems/MEXMAX7

#include <bits/stdc++.h>
using namespace std;

const int MOD = 998244353;

long long myPow(int f) {
    long long ans = 1;
    while(f>0) {
        ans = ans << 1;
        ans %= MOD;
        f--;
    }
    return ans;
}

int main() {
    
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t, n, a;
    cin >> t;
    while (t--) {
        unordered_map<int, int> freq;
        cin >> n;
        int mx = 0;
        for(int i=0; i<n; i++) {
            cin >> a;
            freq[a]++;
            mx = max(mx, a);
        }
        
        vector<long long> perm(mx+1, 0), curPerm(mx+1, 0);
        
        for(int i=0; i<=mx; i++) curPerm[i] = (myPow(freq[i])-1) % MOD;

        perm[0] = curPerm[0];
        for(int i=1; i<=mx; i++) perm[i] = (curPerm[i] * perm[i-1]) % MOD;

        long long ans = perm[0];

        if(freq[0] == 0) {
            cout << curPerm[1] << endl;
            continue;
        }
        
        for(int i=1; i<=mx; i++) {
            if(freq[i]==0) continue;
            ans += perm[i];
            ans %= MOD;
            if(i>1) ans += perm[i-2]*curPerm[i];
            else ans += curPerm[1];
            ans %= MOD;
            // cout << "ans: " << ans << endl;
        }
        
        cout << ans%MOD << endl;
    
    }
}