#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
  
    void merge(vector<int>& a, int l, int mid, int r, int& ans) {
        vector<int>temp;
        int i = l, j = mid+1;
        while(i<=mid && j<=r) {
            if(a[i]>a[j]) {
                temp.push_back(a[j]);
                ans += mid-i+1;
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
        
        for(int i=l; i<=r; i++) a[i] = temp[i-l];
    }
    
    void merge_sort(vector<int>& v, int left, int right, int& ans) {
        if(left>=right) return;
        int mid = left+(right-left)/2;
        merge_sort(v, left, mid, ans);
        merge_sort(v, mid+1, right, ans);
        merge(v, left, mid, right, ans);
    }
    
    
    int inversionCount(vector<int> &a) {
        // Code Here
        int n = a.size();
        int ans = 0;
        merge_sort(a, 0, n-1, ans);
        return ans;
    }
};