
class Solution {
public:

    void merge(vector<int>& a, int l, int mid, int r) {
        vector<int> temp;
        int i = l, j = mid+1;

        while(i<=mid && j<=r) {
            if(a[i]>a[j]) {
                temp.push_back(a[j]);
                j++;
            }
            else {
                temp.push_back(a[i]);
                i++;
            }
        }

        while(i<=mid) {
            temp.push_back(a[i]);
            i++;
        }
        while(j<=r) {
            temp.push_back(a[j]);
            j++;
        }
        for(int i=l; i<=r; i++) {
            a[i] = temp[i-l];
        }
    }

    void countPairs(vector<int> &a, int l, int mid, int r, int& ans) {
        int i=l, j=mid+1;
        while(i<=mid && j<=r) {
            if(a[i]> (long long)2*a[j]) {
                ans += mid-i+1;
                j++;
            }
            else i++;
        }
    }

    void merge_sort(vector<int>& a, int l, int r, int& ans) {
        if(l>=r) return;
        int mid = l + (r-l)/2;
        merge_sort(a, l, mid, ans);
        merge_sort(a, mid+1, r, ans);
        countPairs(a, l, mid, r, ans);
        merge(a, l, mid, r);
    }

    int reversePairs(vector<int>& nums) {
        int n = nums.size(), ans = 0;
        merge_sort(nums, 0, n-1, ans);
        cout << endl;
        return ans;
    }
};