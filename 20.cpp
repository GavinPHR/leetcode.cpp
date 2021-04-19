#include <vector>
#include <iostream>

using namespace std;

// standard stack
class Solution {
public:
    bool isValid(string s) {
        vector<char> stack;
        for (auto p: s) {
            if (p == '[' || p == '(' || p == '{') {
                stack.push_back(p);
            } else if (!stack.size() || 
                       stack.back() == '[' && p != ']' ||
                       stack.back() == '(' && p != ')' ||
                       stack.back() == '{' && p != '}') {
                return false;
            } else {
                stack.pop_back();
            }
        }
        return stack.size() ? false : true;
    }
};

int main(int argc, char const *argv[]) {
    Solution s = Solution();
    cout << s.isValid("]");
    return 0;
}