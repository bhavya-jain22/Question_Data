
// https://www.codechef.com/problems/EXPHOTO

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define vi vector<int>
#define vvi vector<vector<int>>

void solve();
void build(vi& seg, int st, int end, int node);
void updatePoint(vi& seg, int st, int end, int idx, int val, int node);
int queryRange(vi& seg, int st, int end, int l, int r, int node);

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}

void solve() {
    int n, k; 
    cin >> n >> k;  
    vector<int> a(n);  
    vi ind(n + 1);  
    for (int i = 0; i < n; i++) {  
        cin >> a[i];  
        ind[a[i]] = i;  
    }

    bool alreadySorted = true;  
    for (int i = 0; i < n; i++) {  
        if (a[i] != n - i) {  
            alreadySorted = false;  
            break;  
        }  
    }

    if (alreadySorted) {  
        cout << 0 << "\n";  
        return;  
    }

    if (k == 1) {  
        cout << -1 << "\n";  
        return;  
    }

    vi seg(4 * n, 0);  
    build(seg, 0, n - 1, 0); // Each leaf stores 1 (element present)

    k--; // k is now maximum step size (K - 1)
    ll ans = 0;  

    for (int i = n; i > 1; i--) {  
        // Number of remaining smaller elements originally to the left of ind[i]
        int dist = (ind[i] > 0) ? queryRange(seg, 0, n - 1, 0, ind[i] - 1, 0) : 0;
        
        if (dist > 0) {
            ans += (dist + k - 1) / k; // integer ceil
        }
        
        // Remove element i so it doesn't count for subsequent smaller elements
        updatePoint(seg, 0, n - 1, ind[i], -1, 0);
    }  
    cout << ans << "\n";
}

void build(vi& seg, int st, int end, int node) {
    if (st == end) {
        seg[node] = 1;
        return;
    }
    int mid = (st + end) / 2;
    build(seg, st, mid, 2 * node + 1);
    build(seg, mid + 1, end, 2 * node + 2);
    seg[node] = seg[2 * node + 1] + seg[2 * node + 2];
}

void updatePoint(vi& seg, int st, int end, int idx, int val, int node) {
    if (st == end) {
        seg[node] += val;
        return;
    }
    int mid = (st + end) / 2;
    if (idx <= mid) updatePoint(seg, st, mid, idx, val, 2 * node + 1);
    else updatePoint(seg, mid + 1, end, idx, val, 2 * node + 2);
    seg[node] = seg[2 * node + 1] + seg[2 * node + 2];
}

int queryRange(vi& seg, int st, int end, int l, int r, int node) {
    if (r < st || end < l) return 0;
    if (l <= st && end <= r) return seg[node];
    int mid = (st + end) / 2;
    return queryRange(seg, st, mid, l, r, 2 * node + 1) + 
           queryRange(seg, mid + 1, end, l, r, 2 * node + 2);
}