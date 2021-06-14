class Solution {
public:
    // int rob(vector<int>& nums) {
    //     if (nums.size() == 1) return nums[0];
    //     if (nums.size() == 2) return max(nums[0], nums[1]);
    //     if (nums.size() == 3) return max(nums[0] + nums[2], nums[1]);
    //     vector<int> dp(nums.size(), 0);
    //     dp[0] = nums[0];
    //     dp[1] = nums[1];
    //     dp[2] = nums[2] + nums[0];
    //     int ans = max(max(dp[0], dp[1]), dp[2]);
    //     for (int i = 3; i < nums.size(); ++i) {
    //         dp[i] = max(dp[i - 3], dp[i - 2]) + nums[i];
    //         ans = max(ans, dp[i]);
    //     }
    //     return ans;
    // }
    int rob(vector<int>& nums) {
        if (nums.size() == 1) return nums[0];
        if (nums.size() == 2) return max(nums[0], nums[1]);
        int pprev = nums[0], prev = max(nums[0], nums[1]);
        for (int i = 2; i < nums.size(); ++i) {
            int tmp = max(pprev + nums[i], prev);
            pprev = prev;
            prev = tmp;
        }
        return max(pprev, prev);
    }
};