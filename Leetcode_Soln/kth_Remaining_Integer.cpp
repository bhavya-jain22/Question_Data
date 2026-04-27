class Solution {
public:
    vector<int> kthRemainingInteger(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size();
        vector<int> last_even(n);
        vector<int> even(n);
        int evens = 0, l_e = 0;
        for(int i=0; i<n; i++) {
            if(!(nums[i]&1)) {  //even
                l_e = nums[i];
                evens++;
            }
            even[i] = evens;
            last_even[i] = l_e;
        }

        vector<int> ans;

        n = queries.size();
        for(int i=0; i<n; i++) {
            int l = queries[i][0];
            int r = queries[i][1];
            int k = queries[i][2];
            
            if(last_even[l] > 2*k) {
                ans.push_back(2*k);
                continue;
            }
            int low = k, high = k+even[r];
            int let = low;
            while(low<high) {
                int mid = low + (high-low)/2;

                int ind = upper_bound(last_even.begin()+l, last_even.begin()+r+1, 2*mid) - last_even.begin() -1;
                
                int right = min(ind, r);
                int removed = even[right];
                if(l>0) removed -= even[l-1];
                
                if(mid >= k+removed) high = mid;
                else low = mid+1;
            }
            ans.push_back(2*low);
        }
        return ans;
    }
};