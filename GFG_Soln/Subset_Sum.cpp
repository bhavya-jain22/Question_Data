#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
  
    bool ans = false;
    int n;
    void addd(vector<int>& a, int target, int& sum, int i) {
        if(ans) return;
        if(sum == target) {
            ans = true;
            return;
        }
        for(int j=i; j<n; j++) {
            if(sum+a[j]<=target) {
                sum+=a[j];
                addd(a, target, sum, j+1);
                sum-=a[j];
            }
                
        }
    }
    
    bool isSubsetSum(vector<int>& a, int target) {
        n = a.size();
        int sum = 0;
        addd(a, target, sum, 0);
        return ans;
    }
};