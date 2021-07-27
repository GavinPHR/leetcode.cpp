class Solution {
public:
    unordered_map<char, string> pad = {{'2', "abc"},
                                       {'3', "def"},
                                       {'4', "ghi"},
                                       {'5', "jkl"},
                                       {'6', "mno"},
                                       {'7', "pqrs"},
                                       {'8', "tuv"},
                                       {'9', "wxyz"}};

    void rec(const string &digits, int i, string &stack, vector<string> &ans) {
        if (i == digits.size()) {
            string copy = stack;
            ans.push_back(copy);
        }
        for (auto &c : pad[digits[i]]) {
            stack.push_back(c);
            rec(digits, i + 1, stack, ans);
            stack.pop_back();
        }
    }

    vector<string> letterCombinations(string digits) {
        if (digits.size() == 0) return {};
        vector<string> ans;
        string stack;
        rec(digits, 0, stack, ans);
        return ans;
    }
};