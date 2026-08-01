class Solution {
private:
    long long myDivide(long long a, long long b) {
        if(a<b) return 0;
        long long num = b;
        long long ans = 1;
        while(a>=num) {
            ans <<= 1;
            num <<= 1;
        }
        // cout << ans << endl;
        return (ans>>1) + divide(a-(num>>1), b);
        return -1;
    }

public:
    int divide(int a, int b) {
        bool negative = false;
        if((a<0 && b>0) || (a>0 && b<0)) negative = true;
        long long dividend = a, divisor = b;

        long long ans = myDivide(abs(dividend), abs(divisor));
        if(negative) ans = -ans;
        if(ans<INT_MIN) return INT_MIN;
        if(ans>INT_MAX) return INT_MAX;
        return ans;
    }
};