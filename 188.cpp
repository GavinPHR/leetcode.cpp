class Solution {
public:
    void print(vector<vector<int>> &vec) {
        auto a = vec.size(), b = vec[0].size();
        for (int i = 0; i < a; ++i) {
            for (int j = 0; j < b; ++j) {
                cout << vec[i][j] << " ";
            }
            cout << endl;
        }
    }

    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> buy(n, vector<int>(k + 1, 0));
        vector<vector<int>> sell(n, vector<int>(k + 1, 0));
        for (int j = 1; j < k + 1; ++j) {
            buy[0][j] = INT_MIN / 2;
            sell[0][j] = INT_MIN / 2;
        }
        buy[0][1] = -prices[0];
        for (int i = 1; i < n; ++i) {
            int price = prices[i];
            for (int j = 1; j < k + 1; ++j) {
                buy[i][j] = max(buy[i - 1][j], sell[i - 1][j - 1] - price);
                sell[i][j] = max(sell[i - 1][j], buy[i - 1][j] + price);
            }
        }
        int ans = 0;
        for (auto v : sell[n - 1]) ans = max(ans, v);
        // print(buy);
        // print(sell);
        return ans;
    }
};
