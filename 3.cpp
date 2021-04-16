#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int l = 0, r = 0, ans = 0, size = s.size();
        unordered_set<char> set;
        while (r < size) {
            while (set.find(s[r]) != set.end()) {
                set.erase(s[l]);
                ++l;
            }
            set.insert(s[r]);
            ++r;
            ans = r - l > ans ? r - l : ans;
        }
        return ans;
    }
};

int main(int argc, char const *argv[]) {
    Solution s = Solution();
    cout << s.lengthOfLongestSubstring("abcabcbb");
    cout << s.lengthOfLongestSubstring("bbbbb");
    cout << s.lengthOfLongestSubstring("pwwkew");
    cout << s.lengthOfLongestSubstring("");
    return 0;
}