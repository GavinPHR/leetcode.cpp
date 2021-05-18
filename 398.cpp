class Solution {
public:
    vector<int>::iterator begin, end;
    Solution(vector<int>& nums) {
        begin = nums.begin();
        end = nums.end();
    }
    
    int pick(int target) {
        int ans = 0;
        int i = 0;
        for (auto it = begin; it != end; ++it) {
            if (*it == target) {
                ++i;
                if (rand() % i == 0) {
                    ans = it - begin;
                }
            }
        }
        return ans;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(nums);
 * int param_1 = obj->pick(target);
 */