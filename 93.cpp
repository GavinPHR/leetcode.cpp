class Solution {
public:
    void dfs(string &s, int start, vector<string>& stack, vector<string>& result) {
        // for (auto &j : stack) cout << j << " ";
        // cout << endl;
        if (s.size() - start > 12 - 3 * stack.size()) return;
        if (stack.size() == 4) {
            result.push_back(stack[0] + "." + stack[1] + "." + stack[2] + "." + stack[3]);
            return;
        }
        if (start + 1 <= s.size()) {
            stack.push_back(s.substr(start, 1));
            dfs(s, start + 1, stack, result);
            stack.pop_back();
        } 
        if (start + 2 <= s.size() && s[start] != '0') {
            stack.push_back(s.substr(start, 2));
            dfs(s, start + 2, stack, result);
            stack.pop_back();
        }
        if (start + 3 <= s.size() && s[start] != '0') {
            if ((s[start] == '1') ||
                (s[start] == '2' && s[start + 1] < '5') ||
                (s[start] == '2' && s[start + 1] == '5' && s[start + 2] <= '5')) {
                stack.push_back(s.substr(start, 3));
                dfs(s, start + 3, stack, result);
                stack.pop_back();
            }
        }
    }

    vector<string> restoreIpAddresses(string s) {
        vector<string> stack, result;
        dfs(s, 0, stack, result);
        return result;
    }
};