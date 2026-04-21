#include<bits/stdc++.h>
using namespace std;


class Solution {
private:
    int n;

    bool isValid(vector<vector<char>>& board, int r, int c, char num) {
        int row = r/3*3;
        int col = c/3*3;
        for(int i=0; i<n; i++) {
            if(board[r][i] == num) return false;
            if(board[i][c] == num) return false;
        }
        for(int i=row; i<row+3; i++) {
            for(int j=col; j<col+3; j++) {
                if(board[i][j] == num) return false;
            }
        }
        return true;
    }

    bool tryPutting(vector<vector<char>>& board) {
        for(int i=0; i<9; i++) {
            for(int j=0; j<9; j++) {
                if(board[i][j] == '.') {
                    bool valid = false;
                    for(char num='1'; num<='9'; num++) {
                        if(isValid(board, i, j, num)) {
                            // cout << "for ("<<i<<","<<j<<")"<< " num: "<< num << " is valid\n" ; 
                            valid = true;
                            board[i][j] = num;
                            if(tryPutting(board) == false) {
                                valid = false;
                                board[i][j] = '.';
                            }
                        }
                    }
                    if(!valid) return false;
                    return true;
                }
            }
        }
        return true;
    }

public:
    void solveSudoku(vector<vector<char>>& board) {
        n = board.size();
        tryPutting(board);
    }
};