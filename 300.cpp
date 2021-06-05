class Solution {
public:
    // int lengthOfLIS(vector<int>& nums) {
    //     vector<int> memo(nums.size(), 1);
    //     memo[0] = 1;
    //     int ans = 1;
    //     for (int i = 1; i < nums.size(); ++i) {
    //         for (int j = 0; j < i; ++j) {
    //             if (nums[i] > nums[j]) {
    //                 memo[i] = max(memo[i], memo[j] + 1);
    //             }
    //             ans = max(ans,memo[i]);
    //         }
    //     }
    //     return ans;
    // }
    int lengthOfLIS(vector<int>& nums) {
        // Quite tricky, hard to think of this solution
        vector<int> greedy(nums.size(), 1);
        greedy[0] = nums[0];
        int i = 1;
        for (auto &n : nums) {
            int l = 0, r = i - 1;
            while (l < r) {
                int mid = l + (r - l) / 2;
                if (greedy[mid] < n) {
                    l = mid + 1;
                } else {
                    r = mid;
                }
            }
            if (greedy[l] < n) {
                greedy[i] = n;
                ++i;
            } else {
                greedy[l] = n;
            }
        }
        return i;
    }
};