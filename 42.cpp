class Solution {
public:
    int trap(vector<int>& height) {
        int i = 0;
        int j = height.size() - 1;
        int left_max = 0;
        int right_max = 0;
        int ans = 0;
        while (i < j) {
            if (height[i] < height[j]) {
                left_max = max(left_max, height[i]);
                ans += left_max - height[i];
                ++i;
            } else {
                right_max = max(right_max, height[j]);
                ans += right_max - height[j];
                --j;
            }
        }
        return ans;
    }
};