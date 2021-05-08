class Solution {
public:
    bool isMatch(string s, string p) {
        int n = s.size(), m = p.size();
        vector<vector<bool>> dp(n + 1, vector<bool>(m + 1, false));
        dp[0][0] = true;
        // If s is not empty and p is, definitely not match
        // Converse not true s = "", p = "a*"
        // So i start from 0, but j start from 1
        for (int i = 0; i <= n; ++i) {
            for (int j = 1; j <= m; ++j) {
                if (p[j - 1] == '*') {
                    // match 0 time
                    dp[i][j] = dp[i][j] || dp[i][j - 2];
                    // match 1 time, same as no * applied
                    dp[i][j] = dp[i][j] || dp[i][j - 1];
                    // check more time, only if the current char matches k in k*
                    if (i > 1 && (s[i - 1] == p[j - 2] || p[j - 2] == '.')) {
                        dp[i][j] = dp[i][j] || dp[i - 1][j];
                    }
                } else if (i > 0 && (p[j - 1] == '.' || s[i - 1] == p[j - 1])) {
                    dp[i][j] = dp[i - 1][j - 1];
                }
            }
        }
        return dp.back().back();
    }
};