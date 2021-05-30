class Solution {
public:
    int partition(vector<int> &nums, int l, int r) {
        int rand_idx = l + (rand() % (r - l + 1));
        swap(nums[rand_idx], nums[r]);
        int pivot = nums[r];
        int i = l - 1;
        for (int j = l; j < r; ++j) {
            if (nums[j] <= pivot) {
                ++i;
                swap(nums[i], nums[j]);
            }
        }
        swap(nums[i + 1], nums[r]);
        return i + 1;
    }

    int findKthLargest(vector<int>& nums, int k) {
        // using small->large partioning
        // kth largest = nums.size() - k + 1 smalleset
        int l = 0, r = nums.size() - 1;
        int pivot = partition(nums, 0, r);
        int target = nums.size() - k;
        while (pivot != target) {
            if (pivot < target) {
                l = pivot + 1;
            } else {
                r = pivot - 1;
            }
            pivot = partition(nums, l, r);
        }
        return nums[pivot];
    }
};