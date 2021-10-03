class Solution {
public:
    vector<int> used;
    vector<vector<int>> ans;
    
    void backtrack(vector<int> &nums, vector<int> &stack) {
        if (stack.size() == nums.size()) ans.push_back(vector<int>(stack));
        for (int i = 0; i < nums.size(); ++i) {
            if (used[i]) continue;
            if (i > 0 && nums[i - 1] == nums[i] && used[i - 1] == false) continue;
            stack.push_back(nums[i]);
            used[i] = true;
            backtrack(nums, stack);
            stack.pop_back();
            used[i] = false;
        }
    }

    vector<vector<int>> permuteUnique(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        used = vector<int>(nums.size(), 0);
        vector<int> stack;
        backtrack(nums, stack);
        return ans;
    }
};