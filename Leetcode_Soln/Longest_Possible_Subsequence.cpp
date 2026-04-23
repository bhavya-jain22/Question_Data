#include<bits/stdc++.h>
using namespace std;

// NORMAL APPROACH -->
// TC -> O(n*(2^n));

// class Solution {

// private:
//     int solve(vector<int>& a, int i) {
//         if(i==0) return 1;
//         int res = 1;
//         for(int prev = 0; prev<i; prev++) {
//             if(a[prev]<a[i]) {
//                 res = max(res, 1+solve(a, prev));
//             }
//         }
//         return res;
//     }

// public:
//     int lengthOfLIS(vector<int>& nums) {
//         int res = 1, n = nums.size();
//         for(int i=0; i<n; i++) {
//             res = max(res, solve(nums, i));
//         }
//         return res;
//     }
// };




// BETTER APPROACH -->
// TC -> O(n^2)



class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        // dp here is just an array to store the longest subsequence before that element
        // initially, let the longest subsequence 1 for each (considering itself only)
        vector<int> dp(n, 1);

        for(int i=0; i<n; i++) {
            for(int j=0; j<i; j++) {
                if(nums[j]<nums[i]) {
                    dp[i] = max(dp[i], 1+dp[j]);
                }
            }
        }

        int ans = *max_element(dp.begin(), dp.end());
        return ans;
    }
};