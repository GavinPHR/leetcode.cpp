class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size(), n = matrix[0].size();
        int l = 0, r = m * n - 1;
        int mid, x;
        while (l <= r) {
            mid = l + (r - l) / 2;
            // cout << l << " " << r << " " << mid << endl;
            x = matrix[mid / n][mid % n];
            if (x < target) {
                l = mid + 1;
            } else if (x > target) {
                r = mid - 1;
            } else {
                return true;
            }
        }
        return false;
    }
};