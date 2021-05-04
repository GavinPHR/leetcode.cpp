class Solution {
public:
    void rec(vector<string> &ans, string &cur, int left, int right) {
        if (!left && !right) {
            ans.push_back(string(cur));
        }
        if (left > 0) {
            cur.push_back('(');
            rec(ans, cur, left - 1, right);
            cur.pop_back();
        }
        if (right > left) {
            cur.push_back(')');
            rec(ans, cur, left, right - 1);
            cur.pop_back();
        }
    }

    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        string cur;
        rec(ans, cur, n, n);
        return ans;
    }
};