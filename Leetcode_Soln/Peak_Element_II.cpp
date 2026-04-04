#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        int n = mat.size();
        int low = 0, high = n-1, mx_ind;
        while(low<=high) {
            int mid = low + (high-low)/2;
            mx_ind = max_element(mat[mid].begin(), mat[mid].end()) - mat[mid].begin();
            if( (mid == 0 || mat[mid-1][mx_ind] < mat[mid][mx_ind]) && (mid==n-1 || mat[mid+1][mx_ind] < mat[mid][mx_ind]) ) {
                return {mid, mx_ind};
            }

            else if( mid != 0 && mat[mid-1][mx_ind] > mat[mid][mx_ind] ) high = mid-1;
            else low = mid+1;
        }
        return {-1, -1};
        
    }
};