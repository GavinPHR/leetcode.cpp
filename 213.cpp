class Solution {
public:
    int rob_(vector<int> &nums, int left, int right) {
        int a = nums[left], b = max(a, nums[left + 1]);
        int i = left + 2;
        while (i < right) {
            int c = max(a + nums[i], b);
            a = b;
            b = c;
            ++i;
            // cout << a << " " << b << endl;
        }
        return b;
    }

    int rob(vector<int>& nums) {
        if (nums.size() == 1) return nums[0];
        if (nums.size() == 2) return max(nums[0], nums[1]);
        return max(rob_(nums, 0, nums.size() - 1), rob_(nums, 1, nums.size()));
    }
};