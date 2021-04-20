#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Greedy
class Solution {
public:
    int jump(vector<int>& nums) {
        int ans = 0, begin = 0, end = 0, new_end;
        while (end < nums.size() - 1) {
            new_end = 0;
            for (int i = begin; i <= end; ++i) {
                new_end = max(new_end, i + nums[i]);
            }
            begin = end + 1;
            end = new_end;
            ++ans;
        }
        return ans;
    }
};

int main(int argc, char const *argv[]) {
    Solution s = Solution();
    vector<int> v = {2,1};
    cout << s.jump(v);
    return 0;
}
