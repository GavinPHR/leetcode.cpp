class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        if (nums.size() == 0) return {-1, -1};
        int left = 0, right = nums.size() - 1;
        int left_interval, right_interval;
        while (left != right) {
            int mid = left + (right - left) / 2;
            if (nums[mid] >= target) {
                right = mid;
            } else {
                left = mid + 1;
            }
        }
        if (nums[left] != target) return {-1, -1};
        left_interval = left;

        left = 0, right = nums.size() - 1;
        while (left != right) {
            int mid = left + (right - left + 1) / 2;
            if (nums[mid] > target) {
                right = mid - 1;
            } else {
                left = mid;
            }
        }
        right_interval = right;
        return {left_interval, right_interval};
    }
};