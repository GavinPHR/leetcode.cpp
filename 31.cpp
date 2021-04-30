class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        if (nums.size() == 1) return;
        int i = nums.size() - 1;
        int j = i;
        while (i > 0) {
            if (nums[i - 1] < nums[i]) break;
            --i;
        }
        if (i == 0) {
            reverse(nums.begin(), nums.end());
            return;
        }
        while (j >= i) {
            if (nums[j] > nums[i - 1]) break;
            --j;
        }
        swap(nums[i - 1], nums[j]);
        reverse(nums.begin() + i, nums.end());
    }
};