class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int res = NULL;
        int diff = NULL;
        sort(nums.begin(), nums.end());
        int i, j, k;
        for (i = 0; i < nums.size() - 2; ++i) {
            j = i + 1;
            k = nums.size() - 1;
            while (j != k) {
                int sum = nums[i] + nums[j] + nums[k];
                int new_diff = sum - target;
                new_diff = new_diff >= 0 ? new_diff : -new_diff;
                if (diff == NULL || new_diff < diff) {
                    res = sum;
                    diff = new_diff;
                }
                if (sum > target) {
                    --k;
                } else if (sum < target) {
                    ++j;
                } else {
                    return target;
                }
            }
        }
        return res;
    }
};