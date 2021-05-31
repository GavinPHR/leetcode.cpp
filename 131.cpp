class Solution {
public:
    void dfs(vector<vector<bool>> &dp, string s, int start, vector<string> &stack, vector<vector<string>> &res) {
        if (start == dp.size()) {
            res.push_back(vector<string>(stack.begin(), stack.end()));
            return;
        }
        for (int i = start; i < dp.size(); ++i) {
            if (dp[start][i]) {
                stack.push_back(s.substr(start, i - start + 1));
                dfs(dp, s, i + 1, stack, res);
                stack.pop_back();
            }
        }
    }

    void all_palindrome(string s, vector<vector<bool>> &dp) {
        // odd
        for (int i = 0; i < s.size(); ++i) {
            dp[i][i] = true;
            int l = i - 1, r = i + 1;
            while (l >= 0 && r < s.size() && s[l] == s[r]) {
                dp[l][r] = true;
                --l;
                ++r;
            }
        }
        // even
        for (int i = 0; i < s.size() - 1; ++i) {
            if (s[i] != s[i + 1]) continue;
            dp[i][i + 1] = true;
            int l = i - 1, r = i + 2;
            while (l >= 0 && r < s.size() && s[l] == s[r]) {
                dp[l][r] = true;
                --l;
                ++r;
            }
        }
    }

    vector<vector<string>> partition(string s) {
        vector<vector<bool>> dp(s.size(), vector<bool>(s.size(), false));
        all_palindrome(s, dp);
        vector<vector<string>> res;
        vector<string> stack;
        dfs(dp, s, 0, stack, res);
        return res;
    }
};