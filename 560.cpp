class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> memo;
        memo[0] = 1;
        int sum = 0;
        int res = 0;
        for (int i = 0; i < nums.size(); ++i) {
            sum += nums[i];
            int comp = sum - k;
            if (memo.find(comp) != memo.end()) {
                res += memo[comp];
            }
            if (memo.find(sum) == memo.end()) {
                memo[sum] = 1;
            } else {
                memo[sum] += 1;
            }
        }
        return res;
    }
};