#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

class Solution {
public:
    int trap(vector<int>& height) {
        int left = 0, right = height.size() - 1;
        int max_left = 0, max_right = 0;
        int ans = 0;
        while (left <= right) { 
            while (left <= right && height[left] <= height[right]) {
                max_left = max(max_left, height[left]);
                ans += max_left - height[left];
                ++left;
            }
            while (left <= right && height[right] <= height[left]) {
                max_right = max(max_right, height[right]);
                ans += max_right - height[right];
                --right;
            }
        }
        return ans;
    }
};

int main(int argc, char const *argv[])
{
    Solution s = Solution();
    vector<int> v = {0,1,0,2,1,0,1,3,2,1,2,1}; // 6
    cout << s.trap(v) << "\n";
    v = vector<int>{4,2,0,3,2,5}; // 9
    cout << s.trap(v);
    return 0;
}
