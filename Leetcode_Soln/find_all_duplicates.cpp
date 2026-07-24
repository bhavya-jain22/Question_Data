// https://leetcode.com/problems/find-all-duplicates-in-an-array/


class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        // use the index as hash map to count the freq of a[i] and increase a[a[i]] by (n+1) each time
        vector<int> ans;
        int n = nums.size();

        // to store elements between 0 <--> (n-1)
        for(auto& x: nums) x--;

        for(int i=0; i<n; i++) {
            int x = nums[i] % n;
            nums[x] += n;
        }
        
        for(int i=0; i<n; i++) {
            if(nums[i]/n == 2) {
                ans.push_back(i+1);
            }
            // to make the nums same as before (although not needed in this Q)
            nums[i] %= n;
            nums[i]++;
        }

        return ans;

    }
};