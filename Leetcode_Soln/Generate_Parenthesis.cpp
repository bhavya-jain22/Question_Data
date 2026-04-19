#include<bits/stdc++.h>
using namespace std;

class Solution {
private:
    vector<string> ans;
    string s;

    void generate(int open, int closed) {
        if(closed == 0) {
            ans.push_back(s);
            return;
        }
        // if we can put open bracket put it  
        if(open>0) {
            s.push_back('(');
            generate(open-1, closed);
            s.pop_back();
        }
        if(open<closed) {
            s.push_back(')');
            generate(open, closed-1);
            s.pop_back();
        }
    }
    
public:
    vector<string> generateParenthesis(int n) {
        generate(n, n);
        return ans;
    }
};