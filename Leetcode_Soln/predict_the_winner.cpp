class Solution {
    private:
    int utils(vector<int>& nums, int l, int r) {
        if(l>r) return 0;
        if(l==r) return nums[l];
        // maximum on its own turn and expect min
        // (because other player will choose the maximum and leaves us with the min possible answer)
        int take_l = nums[l] + min(utils(nums, l+1, r-1), utils(nums, l+2, r));
        int take_r = nums[r] + min(utils(nums, l+1, r-1), utils(nums, l, r-2));
        // now choose the maximum
        return max(take_l, take_r);
    }

public:
    bool predictTheWinner(vector<int>& nums) {
        int n = nums.size();
        int sum = accumulate(nums.begin(), nums.end(), 0);
        int mx = utils(nums, 0, n-1);
        return mx>=sum-mx;
    }
};