class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        vector<vector<int>> ans;
        for (int a = 0; a < n - 3; ++a) {
            if (a != 0 && nums[a] == nums[a - 1]) continue;
            for (int b = a + 1; b < n - 2; ++b) {
                if (b != a + 1 && nums[b] == nums[b - 1]) continue;
                long long partial = nums[a] + nums[b];
                int c = b + 1, d = n - 1;
                bool move_c = false, move_d = false;
                while (c < d) {
                    long long sum = partial + nums[c] + nums[d];
                    if (sum == target) {
                        ans.push_back({nums[a], nums[b], nums[c], nums[d]});
                        move_c = move_d = true;
                    } else if (sum > target) {
                        move_d = true;
                    } else {
                        move_c = true;
                    }
                    if (move_c) {
                        while (c < d && nums[c + 1] == nums[c]) ++c;
                        ++c;
                    }
                    if (move_d) {
                        while (c < d && nums[d - 1] == nums[d]) --d;
                        --d;
                    }
                    move_c = move_d = false;
                }
            }
        }
        return ans;
    }
};