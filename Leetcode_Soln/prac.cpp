#include <bits/stdc++.h>
using namespace std;

long long MOD = 1e9 + 7;
int MAX_H = 0; // Global variable to store the maximum possible height

long long find(vector<vector<vector<int>>>& dp, int r, int g, int h) {
    // Base Case 1: We successfully built all levels up to MAX_H
    if (h == MAX_H + 1) return 1;

    // Base Case 2: We can't build the current level (dead end path)
    if (r < h && g < h) return 0;

    // Memoization check
    if (dp[r][g][h] != -1) return dp[r][g][h];

    long long ways = 0;
    
    // Try building level 'h' with Red blocks
    if (r >= h) {
        ways = find(dp, r - h, g, h + 1) % MOD;
    }
    
    // Try building level 'h' with Green blocks
    if (g >= h) {
        ways = (ways + find(dp, r, g - h, h + 1)) % MOD;
    }

    // Save and return
    return dp[r][g][h] = ways;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    long long r, g;
    cin >> r >> g;

    // 1. Calculate the maximum possible height mathematically
    long long total_blocks = r + g;
    while ((MAX_H + 1LL) * (MAX_H + 2) / 2 <= total_blocks) {
        MAX_H++;
    }

    // 2. Initialize 3D DP table: dp[r+1][g+1][MAX_H+2]
    // WARNING: This will cause Memory Limit Exceeded for R, G up to 200,000!
    vector<vector<vector<int>>> dp(r + 1, vector<vector<int>>(g + 1, vector<int>(MAX_H + 2, -1)));

    // 3. Start recursion from level 1
    cout << find(dp, r, g, 1) << "\n";
    
    return 0;
}