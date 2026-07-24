// https://leetcode.com/problems/find-the-duplicate-number/

class Solution {
public:
    int findDuplicate(vector<int>& arr) {
        int slow = arr[0], fast = arr[0];
        while(1) {
            slow = arr[slow];
            fast = arr[arr[fast]];
            if(slow == fast) break;
        }

        slow = arr[0];

        while(slow != fast) {
            slow = arr[slow];
            fast = arr[fast];
        }

        return slow;
    }
};