class Solution {
public:
    int mySqrt(int x) {
        if (x <= 1) return x;
        int left = 1, right = x / 2;
        while (left != right) {
            long long mid = left + (right - left + 1) / 2;
            long long sqr = mid * mid;
            if (sqr > x) {
                right = mid - 1;
            } else {
                left = mid;
            }
        }
        return left;
    }
};
