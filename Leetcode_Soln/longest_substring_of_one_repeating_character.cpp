
// https://leetcode.com/problems/longest-substring-of-one-repeating-character/

class Solution {
private:
int n, q;
vector<int> ans;
int pre = -1, mx = -1, suff = -1;
// (pre, val, suff);
vector<tuple<int, int, int>> segTree;

void build(const string& s, int l, int r, int node) {
    if(l == r) {
        segTree[node] = {1, 1, 1};
        return;
    }
    int left = 2*node+1, right = 2*node+2, mid = l+(r-l)/2;
    build(s, l, mid, left);
    build(s, mid+1, r, right);


    int leftLen = mid - l + 1;
    int rightLen = r - mid;
    pre = get<0>(segTree[left]);
    suff = get<2>(segTree[right]);
    mx = max(get<1>(segTree[left]), get<1>(segTree[right]));

    if(s[mid] == s[mid + 1]) {
        int cross = get<2>(segTree[left]) + get<0>(segTree[right]);

        mx = max(mx, cross);

        if(get<0>(segTree[left]) == leftLen) pre = leftLen + get<0>(segTree[right]);

        if(get<2>(segTree[right]) == rightLen) suff = get<2>(segTree[left]) + rightLen;
    }

    segTree[node] = {pre, mx, suff};
}

void updateUtils(const string& s, int l, int r, int ind, int node) {
    if(l == r) return;
    int mid = l + (r-l)/2, left = 2*node+1, right=2*node+2;
    if(mid<ind) updateUtils(s, mid+1, r, ind, right);
    else updateUtils(s, l, mid, ind, left);
    
    int leftLen = mid - l + 1;
    int rightLen = r - mid;
    pre = get<0>(segTree[left]);
    suff = get<2>(segTree[right]);
    mx = max(get<1>(segTree[left]), get<1>(segTree[right]));

    if(s[mid] == s[mid + 1]) {
        int cross = get<2>(segTree[left]) + get<0>(segTree[right]);

        mx = max(mx, cross);

        if(get<0>(segTree[left]) == leftLen) pre = leftLen + get<0>(segTree[right]);

        if(get<2>(segTree[right]) == rightLen) suff = get<2>(segTree[left]) + rightLen;
    }

    segTree[node] = {pre, mx, suff};
}

void update(string& s, int ind, char val) {
    s[ind] = val;
    updateUtils(s, 0, n-1, ind, 0);
    ans.push_back(get<1>(segTree[0]));
}

public:
    vector<int> longestRepeating(string s, string queryCharacters, vector<int>& queryIndices) {
        n = s.size();
        segTree.resize(4*n);
        q = queryIndices.size();
        build(s, 0, n-1, 0);

        int ind;
        char val;

        for(int i=0; i<q; i++) {
            ind = queryIndices[i];
            val = queryCharacters[i];
            update(s, ind, val);
        }
        // cout << get<1>(segTree[0]) << endl;

        return ans;


    }
};