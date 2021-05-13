class Solution {
public:
    int superEggDrop(int k, int n) {
        // can further save space, only need 2 columns
        // having full dp table for clarity
        vector<vector<int>> dp(n + 1, vector<int>(k + 1, 0));
        // Base case
        for (int i = 0; i <= n; ++i) dp[i][1] = i; // 1 egg, need to try n times
        for (int j = 0; j <= k; ++j) dp[1][j] = 1; // 1 floor, only need to try once
        // Recursive (i floors, j eggs)
        // Enumerate every floor from 1 to i, if at floor e now
        // there are 2 outcomes:
        // 1. egg breaks -> try [1, e - 1] (e - 1 floors) with j - 1 eggs
        // 1. egg intact -> try [e + 1, i] (i - e floors) with all j eggs
        // we pick the worse one, because trying to find the worst-case
        for (int i = 2; i <= n; ++i) {
            for (int j = 2; j <= k; ++j) {
                // Comlexity too high if enumerate all
                // int best = INT_MAX;
                // for (int e = 1; e <= i; ++e) best = min(best, max(dp[e - 1][j - 1], dp[i - e][j]));
                // Binary search instead O(knlogn), we observe that:
                // for a fix number of eggs y, we need more drops if the number of floors x are larger
                // as e increases, e - 1 increases, i - e decreases, so the min of their max is when they intersect
                // Discrete values, we need to find the middle two candidates and compare which is smaller
                int lo = 1, hi = i;
                while (lo + 1 < hi) {
                    int m = lo + (hi - lo) / 2;
                    if (dp[m - 1][j - 1] < dp[i - m][j]) {
                        lo = m;
                    } else {
                        hi = m;
                    }
                }
                dp[i][j] = min(max(dp[lo - 1][j - 1], dp[i - lo][j]), max(dp[hi - 1][j - 1], dp[i - hi][j])) + 1;
            }
        }
        // for (auto &row : dp) {
        //     for (auto &n : row) {
        //         cout << n << " ";
        //     }
        //     cout << endl;
        // }
        return dp.back().back();
    }
};
