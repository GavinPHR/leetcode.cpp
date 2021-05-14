class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        // unordered_set<int> seen;
        // int ans = 1;
        // for (auto &n : nums) {
        //     if (n < 1) continue;
        //     seen.insert(n);
        //     while (seen.find(ans) != seen.end()) ++ans;
        // }
        // return ans;
        
        // For an array with length N, the missing number
        // can only be in[1, N + 1], we can iteratively slot
        // every number n into the nums[n - 1], then validate
        int N = nums.size();
        for (int i = 0; i < N; ++i) {
            while (nums[i] > 0 && nums[i] < N + 1 && nums[nums[i] - 1] != nums[i] ) {
                swap(nums[nums[i] - 1], nums[i]);
            }
        }
        for (int i = 0; i < N; ++i) {
            if (nums[i] != i + 1) {
                return i + 1;
            }
        }
        return nums.size() + 1;
    }
};
