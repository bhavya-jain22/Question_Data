#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
    
    vector<string> ans;
    string s;
    
    void generate(int n) {
        if(n==0) {
            ans.push_back(s);
            return;
        }
        s.push_back('0');
        generate(n-1);
        s.pop_back();
        
        s.push_back('1');
        generate(n-1);
        s.pop_back();
    }
    
    vector<string> binstr(int n) {
        generate(n);
        return ans;
    }
};