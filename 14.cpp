#include <vector>
#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int k = strs[0].size();
        for (string s: strs) {
            if (k == 0) {
                return "";
            }
            int i = 0;
            while (i < k && i < s.size() && 
                   strs[0][i] == s[i]) {
                ++i;
            }
            k = i;
        }
        return strs[0].substr(0, k);
    }
};

int main(int argc, char const *argv[])
{
    Solution s = Solution();
    vector<string> v = {"flower","flow","flight"};
    cout << s.longestCommonPrefix(v);
    return 0;
}
