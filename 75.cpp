class Solution {
public:
    void sortColors(vector<int>& nums) {
        int n = nums.size();
        int p0 = 0, p1 = 0;
        int tmp;
        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] == 0) {
                tmp = nums[p0];
                nums[p0] = nums[i];
                nums[i] = tmp;
                ++p0;
                if (nums[i] != 1) ++p1;
            } 
            if (nums[i] == 1) {
                tmp = nums[p1];
                nums[p1] = nums[i];
                nums[i] = tmp;
                ++p1;
            }
            // for (auto n : nums) {
            //     cout << n << " ";
            // }
            // cout << endl;
        }
    }
};