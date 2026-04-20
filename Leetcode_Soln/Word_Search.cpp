#include<bits/stdc++.h>
using namespace std;


class Solution {
private:
    int len, rows, cols;
    bool isExist(int r, int c, vector<vector<char>>& board, string& word, int i, vector<vector<bool>>& vis) {
        if(i==len-1 && word[i] == board[r][c]) {
            // cout << "\n\nI: " << i << endl;
            // cout << "r: " << r << "\tc: " << c << "\tboard[r][c]: " <<  board[r][c] << endl;
            return true;
        }
        if(word[i] != board[r][c]) return false;
        if(r<rows-1 && !vis[r+1][c]) {
            // cout << "down\n";
            vis[r+1][c] = true;
            if(isExist(r+1, c, board, word, i+1, vis)) return true;
            vis[r+1][c] = false;
            cout << endl;
        }
        if(r>0 && !vis[r-1][c]) {
            // cout << "\tup\n";
            vis[r-1][c] = true;
            if(isExist(r-1, c, board, word, i+1, vis)) return true;
            vis[r-1][c] = false;
            // cout << endl;
        }
        if(c<cols-1 && !vis[r][c+1]) {
            // cout << "right\n";
            vis[r][c+1] = true;
            if(isExist(r, c+1, board, word, i+1, vis)) return true;
            vis[r][c+1] = false;
            // cout << endl;
        }
        if(c>0 && !vis[r][c-1]) {
            // cout << "left\n";
            vis[r][c-1] = true;
            if(isExist(r, c-1, board, word, i+1, vis)) return true;
            vis[r][c-1] = false;
            // cout << endl;
        }
        return false;
        
    }

public:
    bool exist(vector<vector<char>>& board, string word) {
        rows = board.size(), cols = board[0].size(), len = word.length();
        // cout << "Rows: " << rows << "\tCOLS: " << cols << endl;
        bool ans = false;
        for(int i=0; i<rows; i++) {
            for(int j=0; j<cols; j++) {
                vector<vector<bool>> visited(rows, vector<bool>(cols, false));
                visited[i][j] = true;
                ans = isExist(i, j, board, word, 0, visited);
                if(ans) break;
            }
            if(ans) break;
        }
        return ans;
    }
};



/*
BETTER APPROACH ---->>>

class Solution {
public:

    bool fun(int indx, int i, int j, vector<vector<char> >& board, int n, int m , string &word){
        
        if(board[i][j] != word[indx]) return false;
        if(indx == word.size()-1)return true;

        char temp = board[i][j];
        board[i][j] = ' ';
        //top
        if(i-1>=0 and fun(indx+1, i-1, j, board, n, m, word)) return true;
        //bottom
        if(i+1<n and fun(indx+1, i+1, j, board, n, m, word))return true;
        //left
        if(j-1 >=0  and fun(indx+1, i, j-1, board, n, m, word))return true;
        //right
        if(j+1<m and fun(indx+1, i, j+1, board, n, m, word))return true;

        board[i][j] = temp;
        return false;
    }
    bool exist(vector<vector<char> >& board, string word) {
        //your code goes here
        int n = board.size();
        int m = board[0].size();

        for(int i =0; i<n; i++){
            for(int j=0; j<m; j++){
                if(word[0] == board[i][j]){
                    if(fun(0, i, j, board, n, m, word) == true) return true;
                }
            }
        }
        return false;
    }
};


*/