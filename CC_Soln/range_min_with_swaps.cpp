// https://www.codechef.com/DSAMONDAY014/problems/RMWS


#include <bits/stdc++.h>
using namespace std;

void utils(vector<int>& tree, vector<int>& a, int l, int r, int node);
vector<int> buildSegmentTree(vector<int>& a);
int query (vector<int>& lazy, vector<int>& tree, int l, int r, int start, int end, int node);
void updateRange(vector<int>& lazy, vector<int>& tree, int l, int r, int start, int end, int node, int val);

int main() {
    
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n, q, o, l, r;
    cin >> n;
    vector<int> a(n);
    for(int i=0; i<n; i++) cin >> a[i];
    vector<int> tree = buildSegmentTree(a);
    vector<int> lazy(4*n, 0);
    
    cin >> q;
    while(q--) {
        cin >> o >> l >> r;
        l--; r--;
        if(o==1) {
            int val = a[r]-a[l];
            updateRange(lazy, tree, l, l, 0, n-1, 0, val);
            val = a[l]-a[r];
            updateRange(lazy, tree, r, r, 0, n-1, 0, val);
            swap(a[l], a[r]);
        }
        else {
            cout << query(lazy, tree, l, r, 0, n-1, 0) << endl;
        }
    }
}


void utils(vector<int>& tree, vector<int>& a, int l, int r, int node) {
    if(l==r) {
        tree[node] = a[l];
        return;
    }
    int mid = l + (r-l)/2, left = 2*node+1, right = 2*node+2;
    utils(tree, a, l, mid, left);
    utils(tree, a, mid+1, r, right);
    tree[node] = min(tree[left], tree[right]);
}

vector<int> buildSegmentTree(vector<int>& a) {
    int n = a.size();
    vector<int>tree(4*n, INT_MAX);
    utils(tree, a, 0, n-1, 0);
    return tree;
}

int query (vector<int>& lazy, vector<int>& tree, int l, int r, int start, int end, int node) {
    if(start>end) return INT_MAX;
    
    int left = 2*node+1;
    int right = 2*node+2;
    if(lazy[node]) {
        tree[node] += lazy[node];
        if(start!=end) {
            lazy[left] += lazy[node];
            lazy[right] += lazy[node];
        }
        lazy[node] = 0;
    }
    
    // complete overlapping
    if(l<=start && end<=r) {
        return tree[node];
    }
    // no overlapping
    if(end<l || start>r) return INT_MAX;
    
    int mid = start + (end-start)/2;
    return min(
            query(lazy, tree, l, r, start, mid, left),
            query(lazy, tree, l, r, mid+1, end, right)
        );
    }


void updateRange(vector<int>& lazy, vector<int>& tree, int l, int r, int start, int end, int node, int val) {
    if(start>end) return;
    
    int left = 2*node+1, right = 2*node+2;
    if(lazy[node]) {
        tree[node] += lazy[node];
        if(start!=end) {
            lazy[left] += lazy[node];
            lazy[right] += lazy[node];
        }
        lazy[node] = 0;
    }
    
    // complete overlapping
    if(l<=start && end<=r) {
        tree[node] += val;
        if(start!=end) {
            lazy[left] += val;
            lazy[right] += val;
        }
        return;
    }
    
    // no overlapping
    if(l>end || r<start) {
        return;
    }
    
    int mid = start + (end-start)/2;
    updateRange(lazy, tree, l, r, start, mid, left, val);
    updateRange(lazy, tree, l, r, mid+1, end, right, val);
    tree[node] = min(tree[left], tree[right]);
}