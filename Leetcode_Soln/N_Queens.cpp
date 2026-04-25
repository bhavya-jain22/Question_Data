
class Solution {
    unordered_map<int,bool>cols,left,right;
    void solve(int n,vector<vector<string>>&ans,int row,vector<string> &board){
        if(row==n){
            ans.push_back(board);
            return;
        }
        for(int col=0;col<n;col++){
            if(cols[col]==0 && left[row-col]==0 && right[row+col]==0){
                board[row][col]='Q';
                cols[col]=1;left[row-col]=1;right[row+col]=1;
                solve(n,ans,row+1,board);
                board[row][col]='.';
                cols[col]=0;left[row-col]=0;right[row+col]=0;
            }
        }
    }
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>>ans;
        vector<string> board(n, string(n, '.'));
        solve(n,ans,0,board);
        return ans;
    }
};