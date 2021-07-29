class Solution {
public:
    int divide(int dividend, int divisor) {
        // One difficulty is that -INT_MIN overflows (1 larger than INT_MAX)
        // Frankly using long is the way to avoid the infinite amount of headache
        int sign = 1;
        long long dividendL = dividend, divisorL = divisor;
        if (dividendL < 0) {
            sign = -1;
            dividendL = 0 - dividendL;
        }
        if (divisorL < 0) {
            sign *= -1;
            divisorL = 0 - divisorL;
        }
        long long ans = sign * div(dividendL, divisorL);
        return ans > INT_MAX ? INT_MAX : ans;
    }

    long long div(long long dividendL, long long divisorL) {
        if (divisorL > dividendL) return 0;
        long long ans = 1;
        long long cur = divisorL;
        while (cur * 2 <= dividendL) {
            cur *= 2;
            ans *= 2;
        }
        return ans + div(dividendL - cur, divisorL);
    }
};