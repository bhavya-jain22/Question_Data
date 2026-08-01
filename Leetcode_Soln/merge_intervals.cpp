
// https://leetcode.com/problems/merge-intervals/


// INTUITION
// since the the start and end points are O(n), we can store an array
// +1 interval start
// -1 interval end -> we do -1 for next element since the intervals are inclusive

// but another issues happens if u have like 1,3 and 4,5
// it merges into 1,5 but it shouldnt

// so for this we double the coordinates,
// 2,6 and 8,10
// so now we can safely end interval at 7


class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) 
    {
        vector<int> a(20004);
        for(auto i : intervals)
        {
            a[2*i[0]]++;
            a[2*i[1] + 1]--;
        }

        int start = -1, prefix = 0;
        vector<vector<int>> ans;
        for(int i = 0 ; i <= 20003 ; i++)
        {
            prefix += a[i];
            if(prefix > 0)
            {
                if(start == -1)
                    start = i;
            }
            else if(prefix == 0 && start != -1)
            {
                ans.push_back(vector<int>{start/2,(i-1)/2});
                start = -1;
            }
        }
        return ans;
    }
};