class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int ans = nums[0];
        int min_n = ans, max_n = ans;
        for (int i = 1; i < nums.size(); ++i) {
            int cand1 = min_n * nums[i];
            int cand2 = max_n * nums[i];
            min_n = min(cand1, min(cand2, nums[i]));
            max_n = max(cand1, max(cand2, nums[i]));
            ans = max(ans, max_n);
        }
        return ans;
    }
};