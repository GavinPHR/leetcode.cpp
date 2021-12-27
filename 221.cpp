class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int n = matrix.size(), m = matrix[0].size();
        vector<vector<int>> dp(n, vector<int>(m));
        for (int j = 0; j < m; ++j) dp[0][j] = matrix[0][j] - '0';
        for (int i = 0; i < n; ++i) dp[i][0] = matrix[i][0] - '0';

        for (int i = 1; i < n; ++i) {
            for (int j = 1; j < m; ++j) {
                if (matrix[i][j] == '0') continue;
                dp[i][j] = min(dp[i - 1][j - 1], min(dp[i - 1][j], dp[i][j - 1])) + 1;

            }
        }

        int ans = 0;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                // cout << dp[i][j] << " ";
                ans = max(ans, dp[i][j]);
            }
            // cout << endl;
        }

        return ans * ans;
    }
};