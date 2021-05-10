class Solution {
public:
    int numOfWays(int n) {
        static constexpr long mod = 1000000007;
        /* 3 colours {A, B, C}, every row can be arranged into each ABC or ABA
        *  Problem is symmetric to ABC if a row is BAC, similarly ABA and BAB
        *  Given ABC on i - 1 row, on row i, there can be:
        *  1. BCA, CAB (ABC config)
        *  2. BAB, BCB (ABA config)
        * Given ABA on i - 1 row, on row i, there can be:
        *  1. BAB, CAC, BCB (ABA config)
        *  2. BAC, CAB (ABC config)
        * In the starting position (n=1), there can be:
        *  1. ABC, ACB, BAC, BCA, CAB, CBA (6 ABC config)
        *  2. ABA, ACA, BAB, BCB, CAC, CBC (6 ABA config)
        */
        // Start with an implicit dp table, column 0 = ABC config, column 1 = ABA config
        long col0 = 6, col1 = 6;
        for (int i = 1; i < n; ++i) {
            long tmp_col0 = col0;
            col0 = (2 * col0 + 2 * col1) % mod;
            col1 = (2 * tmp_col0 + 3 * col1) % mod;
        }
        return (col0 + col1) % mod;
    }
};
