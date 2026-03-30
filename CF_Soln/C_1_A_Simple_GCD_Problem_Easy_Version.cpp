#include<bits/stdc++.h>
using namespace std;

int gcd (int a, int b) {
    if(b==0) return a;
    return gcd(b, a%b);
}

int lcm(int a, int b) {
    long long x = 1LL*a*b/gcd(a,b);
    return x;
}

int main () {

    ios::sync_with_stdio(false);
    cin.tie(NULL);

    //#ifndef ONLINE_JUDGE
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //#endif
    int t, n;
    cin >> t;
    while(t--) {
        cin>>n;
        vector<int> a(n), b(n);
        for(int& x: a) cin >> x;
        for(int& x: b) cin >> x;

        int ans = 0, g;
        g = gcd(b[0], b[1]);
        if(g != b[0]) {
            ans++;
            b[0] = g;
        }
        int f, s;
        for(int i=1; i<n-1; i++) {
            f = gcd(b[i-1], b[i]);
            s = gcd(b[i], b[i+1]);
            
            if(lcm(f, s) < b[i]) {
                ans++;
                b[i] = lcm(f, s);
            }

        }
        g = gcd(b[n-1], b[n-2]);
        if(g!=b[n-1]) {
            ans++;
            b[n-1] = g;
        }

        cout << ans << endl;
        // for(int& x: b) cout << x << " ";
        // cout << "\n\n";

    }
    
return 0;
}