
// https://leetcode.com/problems/maximum-area-of-two-non-overlapping-square-submatrices/

class Solution {
public:
    bool isValid(vector<vector<int>>& mat, vector<vector<int>>& maxSquare, int k) {
        if (k == 0) return true;
        int m = mat.size(), n = mat[0].size();
        int minR = INT_MAX, maxR = INT_MIN, minC = INT_MAX, maxC = INT_MIN, count = 0;
        for (int i = k; i <= m; i++) {
            for (int j = k; j <= n; j++) {
                if (maxSquare[i][j] >= k) {
                    count++;
                    minR = min(minR, i); maxR = max(maxR, i);
                    minC = min(minC, j); maxC = max(maxC, j);
                }
            }
        }
        if (count < 2) return false;
        return (maxR - minR >= k) || (maxC - minC >= k);
    }

    int check(vector<vector<int>>& mat, vector<vector<int>>& maxSquare, int k) {
        int l = 0, r = k;
        while (l < r) {
            int mid = l + (r - l + 1) / 2;
            if (isValid(mat, maxSquare, mid)) l = mid;
            else r = mid - 1;
        }
        return l;
    }

    int maxArea(vector<vector<int>>& mat) {
        int m = mat.size(), n = mat[0].size();
        vector<vector<int>> maxSquare(m + 1, vector<int>(n + 1, 0));
        for (int i = 1; i <= m; i++)
            for (int j = 1; j <= n; j++)
                if (mat[i-1][j-1])
                    maxSquare[i][j] = 1 + min({maxSquare[i-1][j], maxSquare[i][j-1], maxSquare[i-1][j-1]});

        int k = min(min(m, n), max(m, n) / 2);
        int side = check(mat, maxSquare, k);
        return side * side;
    }
};