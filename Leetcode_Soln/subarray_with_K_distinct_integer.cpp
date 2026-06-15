class Solution {
public:
    int subSize(vector<int>& nums, int k) {
        int n = nums.size(), l = 0, r = 0, ans = 0;
        unordered_map<int, int> freq;

        for(r; r<n; r++) {
            freq[nums[r]]++;
            while(freq.size() > k && l<=r) {
                freq[nums[l]]--;
                if(!freq[nums[l]]) freq.erase(nums[l]);
                l++;
            }

            if(freq.size() <= k) {
                ans += r-l+1;
            }
        }
        return ans;
    }
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        return subSize(nums, k) - subSize(nums, k-1);
    }
};