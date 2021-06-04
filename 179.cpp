class Solution {
public:
    string largestNumber(vector<int>& nums) {
        vector<string> n(nums.size());
        for (int i = 0; i < nums.size(); ++i) {
            n[i] = to_string(nums[i]);
        }
        sort(n.begin(), n.end(), [](string &a, string &b) {return a + b < b + a;});
        string res = "";
        for (auto it = n.rbegin(); it != n.rend(); ++it) {
            res += *it;
        }
        if (res[0] == '0') return "0";
        return res;
    }
};