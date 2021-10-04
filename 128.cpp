class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> nums_set;
        for (auto n : nums) {
            nums_set.insert(n);
        }
        int ans = 0;
        for (auto it = nums_set.begin(); it != nums_set.end(); ++it) {
            if (nums_set.find(*it - 1) != nums_set.end()) continue;
            int len = 1;
            int k = *it;
            while (nums_set.find(k + 1) != nums_set.end()) {
                ++len;
                ++k;
            }
            ans = max(ans, len);
        }
        return ans;
    }
};