// https://leetcode.com/problems/longest-mountain-in-array/

class Solution {
public:
    int longestMountain(vector<int>& arr) {
        bool mountain = false;
        int l = 0, r, n = arr.size(), ans = 0;
        while(l+1<n && arr[l]>=arr[l+1]) l++;
        for(r=l+1; r<arr.size(); r++) {
            if(!mountain && arr[r]==arr[r-1]) {
                l = r;
                while(l+1<n && arr[l]>=arr[l+1]) l++;
                r = l+1;
            }
            else if(!mountain && arr[r]<arr[r-1]) {
                mountain = true;
            }
            else if (mountain && arr[r]>=arr[r-1]) {
                ans = max(ans, r-l);
                l = r-1;
                if(arr[r] == arr[r-1]) l++;
                mountain = false;
            }
        }
        if(mountain) ans = max(ans, r-l);
        return ans;
    }
};