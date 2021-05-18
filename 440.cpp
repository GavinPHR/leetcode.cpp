class Solution {
public:
    inline int numChildren(int n, int cur) {
        static constexpr int UPPER = INT_MAX / 10 + 1;
        int res = 0;
        int next = cur + 1;
        while (cur < UPPER && cur * 10 <= n) {
            cur *= 10;
            next *= 10;
            res += min(n + 1, next) - cur;
        }
        return res;
    }

    int findKthNumber(int n, int k) {
        int cur = 1;
        int rank = 1;
        while (rank != k) {
            int c = numChildren(n, cur);
            if (k <= rank +  c) {
                ++rank;
                cur *= 10;
            } else {
                ++cur;
                rank += c + 1;
            }
        }
        return cur;
    }
};