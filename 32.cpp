class Solution {
public:
    int longestValidParentheses(string s) {
        vector<int> dp(s.size(), 0);
        int res = 0;
        for (int i = 1; i < s.size(); ++i) {
            if (s[i] == ')') {
                if (s[i - 1] == '(') {
                    dp[i] = i > 1 ? dp[i - 2] + 2 : 2;
                } else {
                    int cand_idx = i - 1 - dp[i - 1];
                    if (cand_idx >= 0 && s[cand_idx] == '(') {
                        dp[i] = dp[i - 1] + 2;
                        if (cand_idx - 1 >= 0) dp[i] += dp[cand_idx - 1];
                    }
                }
            }
            res = max(res, dp[i]);
        }
        // for (auto c : dp) {
        //     cout << c << " ";
        // }
        return res;
    }
};
