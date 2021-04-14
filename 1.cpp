#include <vector>
#include <iostream>
#include <unordered_map>

using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> map;
        for (int i = 0; i < nums.size(); ++i) {
            if (map.find(nums[i]) != map.end()) {
                return {map[nums[i]], i};
            }
            map[target - nums[i]] = i;
        }
        return {};
    }
};

int main(int argc, char const *argv[])
{
    Solution s = Solution();
    vector<int> v = {2, 7, 11, 15};
    for (auto i: s.twoSum(v, 9)) {
        cout << i << " ";
    }
    return 0;
}
