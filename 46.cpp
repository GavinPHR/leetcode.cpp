#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

class Solution {
public:
    void rec(vector<vector<int>>& ans, vector<int>& nums, int i) {
        int size = nums.size();
        if (i == size) {
            ans.push_back(vector<int>(nums));
            return;
        }
        int tmp;
        for (int j = i; j < size; ++j) {
            tmp = nums[i];
            nums[i] = nums[j];
            nums[j] = tmp;
            this->rec(ans, nums, i + 1);
            tmp = nums[i];
            nums[i] = nums[j];
            nums[j] = tmp;
        }
        return;
    }

    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        this->rec(ans, nums, 0);
        return ans;
    }
};

int main(int argc, char const *argv[])
{
    Solution s;
    vector<int> v = {1, 2, 3};
    vector<vector<int>> p = s.permute(v);
    for (auto v: p) {
        for (int i: v) {
            cout << i << " ";
        }
        cout << "\n";
    }
    return 0;
}