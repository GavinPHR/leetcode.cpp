#include <string>
#include <iostream>

using namespace std;

// O(n^2 below), Manacher can do O(n)
class Solution {
public:
    string longestPalindrome(string s) {
        int l, r;
        int best = 0, cur = 0;
        string res;
        for (int i = 0; i < s.size(); ++i) {
            // Odd
            l = r = i;
            while (l >= 0 && r < s.size() && s[l] == s[r]) {
                --l;
                ++r;
            }
            cur = r - l - 1;
            if (cur > best) {
                res = s.substr(l + 1, cur);
                best = cur;
            }
            // Even
            l = i;
            r = i + 1;
            cur = 0;
            while (l >= 0 && r < s.size() && s[l] == s[r]) {
                --l;
                ++r;
                cur += 2;
            }
            if (cur > best) {
                res = s.substr(l + 1, cur);
                best = cur;
            }
        }
        return res;
    }
};

int main(int argc, char const *argv[]) {
    Solution s = Solution();
    cout << s.longestPalindrome("babad");
}