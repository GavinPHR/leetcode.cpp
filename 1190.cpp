class Solution {
public:
    string reverseParentheses(string s) {
        unordered_map<int, int> jump;
        vector<int> stack;
        for (int i = 0; i < s.size(); ++i) {
            if (s[i] == '(') {
                stack.push_back(i);
            } else if (s[i] == ')') {
                int left = stack.back();
                stack.pop_back();
                jump[left] = i;
                jump[i] = left;
            }
        }

        string ans;

        int i = 0;
        int direction = 1; //1=right, -1=left
        while (i < s.size()) {
            if (s[i] == '(' || s[i] == ')') {
                i = jump[i];
                direction = -direction;
            } else {
                ans.push_back(s[i]);
            }
            i += direction;
        }
        return ans;
    }
};