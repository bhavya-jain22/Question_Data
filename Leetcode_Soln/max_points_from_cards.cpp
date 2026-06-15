class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int l = 0, n = cardPoints.size(), totalPoints = 0;
        for(auto& x: cardPoints) totalPoints += x;
        if(n==k) return totalPoints;
        int r = n-k-1, mn = 0;
        for(int i=0; i<=r; i++) mn += cardPoints[i];
        int window = mn;
        r++;
        for(r; r<n; r++, l++) {
            window = window+cardPoints[r]-cardPoints[l];
            mn = min(mn, window);
            cout << window << endl;
        }
        return totalPoints - mn;
    }
};