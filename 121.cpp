class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if (prices.size() < 2) return 0;
        int min_price = 1e9;
        int ans = 0;
        for (auto price : prices) {
            ans = max(ans, price - min_price);
            min_price = min(min_price, price);
        }
        return ans;
    }
};