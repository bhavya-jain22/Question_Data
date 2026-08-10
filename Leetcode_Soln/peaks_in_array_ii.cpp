
// https://leetcode.com/problems/peaks-in-array-ii/

class Solution {
private:
int n;
vector<long long> lazy, segTree;
vector<long long> ans;
set<int> s;
vector<int> nums;

void updateRange(int start, int end, int l, int r, int node, long long val) {
    int left = 2*node + 1, right = 2*node + 2;
    if(lazy[node]) {
        segTree[node] += (end-start+1) * lazy[node];
        if(start != end) {
            lazy[left] += lazy[node];
            lazy[right] += lazy[node];
        }
        lazy[node] = 0;
    }
    if(l<=start && end <= r) {
        segTree[node] += (1LL*val)*(end-start+1);
        if(start != end) {
            lazy[left] += val;
            lazy[right] += val;
        }
        return;
    }
    if(r<start || end<l) return;
    int mid = (start + end) / 2;
    updateRange(start, mid, l, r, left, val);
    updateRange(mid+1, end, l, r, right, val);
    segTree[node] = segTree[left] + segTree[right];
}

void build(int l, int r) {
    updateRange(0, n-1, l+1, r, 0, l);
}

long long query(int start, int end, int l, int r, int node) {
    int left = 2*node + 1, right = 2*node + 2;
    if(lazy[node]) {
        segTree[node] += (end-start+1) * lazy[node];
        if(start != end) {
            lazy[left] += lazy[node];
            lazy[right] += lazy[node];
        }
        lazy[node] = 0;
    }
    if(l<=start && end<=r) return segTree[node];
    if(r<start || end<l) return 0;
    int mid = (start + end) / 2;
    return 0LL + query(start, mid, l, r, left) + query(mid+1, end, l, r, right);
}

bool isPeak(int ind) {
    return nums[ind] > nums[ind-1] && nums[ind] > nums[ind+1];
}

// Reconcile the peak status of a single interior position against the
// segment tree / set, using position-based deltas (never array values).
void reconcile(int pos) {
    if (pos < 1 || pos > n-2) return; // only interior indices can be peaks
    bool wasPeak = s.count(pos);
    bool nowPeak = isPeak(pos);
    if (wasPeak == nowPeak) return;

    if (nowPeak) {
        // insertion: find tightest bracket (L, R) in s around pos
        auto R_it = s.upper_bound(pos);
        auto L_it = prev(R_it);
        int R = *R_it, L = *L_it;
        s.insert(pos);
        if (pos+1 <= R) updateRange(0, n-1, pos+1, R, 0, pos - L);
    } else {
        // removal: find neighbors in s while pos is still a member
        auto it = s.find(pos);
        auto R_it = next(it);
        auto L_it = prev(it);
        int R = *R_it, L = *L_it;
        s.erase(it);
        if (pos+1 <= R) updateRange(0, n-1, pos+1, R, 0, L - pos);
    }
}

public:
    vector<long long> countOfPeaks(vector<int>& numsIn, vector<vector<int>>& queries) {
        nums = numsIn;
        n = nums.size();
        lazy.assign(4*n, 0);
        segTree.assign(4*n, 0);
        ans.clear();
        s.clear();
        s.insert(0);
        s.insert(n-1);
        for(int i=1; i<n-1; i++) {
            if(isPeak(i)) s.insert(i);
        }

        if((int)s.size() > 2) {
            auto curr = s.begin();
            auto nxt = s.begin();
            advance(curr, 1);
            advance(nxt, 2);
            while(nxt != s.end()) {
                build(*curr, *nxt);
                advance(curr, 1);
                advance(nxt, 1);
            }
        }

        for(auto& q: queries) {
            if(q[0] == 1) {
                int l = q[1], r = q[2];
                auto lb_it = s.lower_bound(l);
                long long lb = *lb_it;
                long long a = 0;
                if (lb <= r) {
                    long long sumFull   = query(0, n-1, 0, r, 0);        // sum p(j), j=0..r
                    long long sumUpToLb = query(0, n-1, 0, (int)lb, 0);  // sum p(j), j=0..lb
                    a = (sumFull - sumUpToLb) - l * (r - lb);
                }
                if (a < 0) a = 0;
                ans.push_back(a);
            } else {
                int ind = q[1], val = q[2];
                nums[ind] = val;
                // updating nums[ind] can change peak status at ind-1, ind, ind+1
                reconcile(ind - 1);
                reconcile(ind);
                reconcile(ind + 1);
            }
        }
        return ans;
    }
};