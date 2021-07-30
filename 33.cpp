class Solution {
public:
    int search(vector<int>& nums, int target) {
        int l = 0, r = nums.size() - 1;
        int mid = 0;
        while (l < r) {
            // cout << l << " " << r << endl;
            mid = l + (r - l) / 2;
            if (nums[mid] == target) return mid;
            if (nums[mid + 1] <= nums[r]) { // rhs is ordered
                if (target >= nums[mid + 1] && target <= nums[r]) {
                    l = mid + 1;
                } else {
                    r = mid;
                }
            }
            else { // lhs is ordered
                if (target >= nums[l] && target <= nums[mid]) {
                    r = mid;
                } else {
                    l = mid + 1;
                }
            }

        }
        if (nums[l] == target) return l;
        return -1;
    }
};