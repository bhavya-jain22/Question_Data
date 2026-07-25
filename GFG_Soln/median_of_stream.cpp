
// https://www.geeksforgeeks.org/problems/find-median-in-a-stream-1587115620/1

class Solution {
  public:
    vector<double> getMedian(vector<int> &arr) {
        // code here
        priority_queue<int> mx;
        priority_queue<int, vector<int>, greater<>> mn;
        vector<double> ans;
        int n = arr.size();
        
        mx.push(arr[0]);
        ans.push_back(arr[0]);
        
        int s1=1, s2=0;
        for(int i=1; i<n; i++) {
            
            if(arr[i] <= mx.top()) {mx.push(arr[i]); s1++;}
            else {mn.push(arr[i]); s2++;}
            
            
            if(abs(s1-s2) > 1) {
                if(mx.size()>mn.size()) {
                    mn.push(mx.top());
                    mx.pop();
                    s2++;
                    s1--;
                }
                else {
                    mx.push(mn.top());
                    mn.pop();
                    s1++;
                    s2--;
                }
            }
            
            if(s1 == s2) ans.push_back((mx.top() + mn.top()) / 2.0);
            else if(s1>s2) ans.push_back(mx.top());
            else ans.push_back(mn.top());
        }
        
        return ans;
    }
};
