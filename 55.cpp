class Solution {
public:
    bool canJump(vector<int>& nums) {
        int can_jump = 0;
        int cur = 0;
        while (cur < nums.size() && cur <= can_jump) {
            can_jump = max(can_jump, cur + nums[cur]);
            ++cur;
        }
        if (can_jump >= nums.size() - 1) return true;
        return false;
    }
};