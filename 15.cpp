#include <vector>
#include <unordered_set>
#include <unordered_map>
#include <iostream>
#include <algorithm>

using namespace std;

// Interesing and slightly difficult
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ans;
        int size = nums.size();
        sort(nums.begin(), nums.end());
        int i, j, k, partial;
        for (i = 0; i < size - 2; ++i) {
            if (i > 0 && nums[i] == nums[i - 1]) {
                continue;
            }
            k = size - 1;
            for (j = i + 1; j < size - 1; ++j) {
                if (j > i + 1 && nums[j] == nums[j - 1]) {
                    continue;
                }
                if (j >= k) {
                    break;
                }
                partial = nums[j] + nums[k];
                while (partial > -nums[i] && k > j + 1) {
                    --k;
                    partial = nums[j] + nums[k];
                }
                if (partial == -nums[i]) {
                    ans.push_back(vector<int>{nums[i], nums[j], nums[k]});
                } else {
                    continue;
                }
            }
        }
        return ans;
    }
};

int main(int argc, char const *argv[])
{
    Solution s = Solution();
    vector<int> v = {-1,0,1,2,-1,-4};
    for (auto v: s.threeSum(v)) {
        for (auto i: v) {
            cout << i << " ";
        }
        cout << "\n";
    }
    return 0;
}
