class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int ans = INT_MIN;
        int cumsum = 0;
        for (int n: nums) {
            if (cumsum <= 0) {
                cumsum = n;
            } else {
                cumsum += n;
            }
            ans = max(ans, cumsum);
        }
        return ans;
    }
};
