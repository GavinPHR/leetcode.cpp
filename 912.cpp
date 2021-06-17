class Solution {
public:
    void qSort(vector<int> &nums, int p, int r) {
        if (p >= r) return;
        int pivot = p + (rand() % (r - p + 1));
        swap(nums[r], nums[pivot]);
        pivot = nums[r];
        int i = p - 1;
        for (int j = p; j < r; ++j) {
            if (nums[j] <= pivot) {
                swap(nums[++i], nums[j]);
            }
        }
        swap(nums[++i], nums[r]);
        qSort(nums, p, i - 1);
        qSort(nums, i + 1, r);
    }

    vector<int> sortArray(vector<int>& nums) {
        qSort(nums, 0, nums.size() - 1);
        // sort(nums.begin(), nums.end());
        return nums;
    }
};