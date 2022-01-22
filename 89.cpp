class Solution {
public:
    vector<int> grayCode(int n) {
        if (n == 0) return {0};
        int N = pow(2, n);
        vector<int> res(N);
        vector<int> prev = grayCode(n - 1);
        for (int i = 0; i < N / 2; ++i) res[i] = prev[i];
        int prepend = 1 << (n - 1);
        for (int i = 0; i < N / 2; ++i) {
            res[N - i - 1] = res[i] | prepend;
        }
        return res;
    }
};