#include <vector>
#include <iostream>

using namespace std;

// Slow
// class Solution {
// public:
//     bool isPalindrome(int x) {
//         if (x < 0) return false;
//         vector<int> v;
//         while (x) {
//             v.push_back(x % 10);
//             x /= 10;
//         }
//         if (v.size() <= 1) return true;
//         int l = 0, r = v.size() - 1;
//         while (l < r) {
//             if (v[l] != v[r]) return false;
//             ++l;
//             --r;
//         }
//         return true;
//     }
// };

class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0 || (x % 10 == 0 && x != 0)) return false;
        int y = 0;
        while (y < x) {
            y = y * 10 + x % 10;
            x /= 10;
        }
        return y == x || y / 10 == x;
    }
};


int main(int argc, char const *argv[]) {
    Solution s = Solution();
    cout << s.isPalindrome(121);
    return 0;
}
