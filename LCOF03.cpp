#include <unordered_set>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int findRepeatNumber(vector<int>& nums) {
        unordered_set<int> seen;
        for (int n: nums) {
            if (seen.find(n) != seen.end()) {
                return n;
            }
            seen.insert(n);
        }
        return 0;
    }
};

int main(int argc, char const *argv[]) {
    Solution s = Solution();
    vector<int> v = {2, 3, 1, 0, 2, 5, 3};
    cout << s.findRepeatNumber(v);
    return 0;
}

