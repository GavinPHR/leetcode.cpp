class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int low = prices[0];
        int ans = 0;
        for (auto &price : prices) {
            if (price < low) low = price;
            ans = max(ans, price - low);
        }
        return ans;
    }
};