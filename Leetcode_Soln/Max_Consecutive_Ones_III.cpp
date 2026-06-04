class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int n = nums.size();
        int l = 0, ans = 0, cnt = 0;
        for(int r = 0; r < n; r++){
            if(nums[r] == 0) cnt++;
            if(cnt > k){
                if(nums[l] == 0) cnt--;
                l++;
            }
            ans = max(ans, r-l+1);
        }
        return ans;
    }
};