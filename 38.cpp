class Solution {
public:
    string countAndSay(int n) {
        if (n == 1) return "1";
        string ans = "";
        string prev = countAndSay(n - 1);
        // cout << prev << endl;
        int count = 1;
        int i = 1;
        char cur = prev[0];
        while (i < prev.size()) {
            if (prev[i] != cur) {
                ans.push_back('0' + count);
                ans.push_back(cur);
                cur = prev[i];
                count = 1;
            } else {
                ++count;
            }
            ++i;
        }
        // cout << count << " " << cur << endl;
        ans.push_back('0' + count);
        ans.push_back(cur);
        return ans;
    }
};