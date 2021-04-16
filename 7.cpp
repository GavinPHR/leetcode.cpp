#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int reverse(int x) {
        int ans = 0, remainder, lower = INT_MIN / 10, upper = INT_MAX / 10;
        while (x != 0) {
            // -17 % 10 = -1 in C++
            // -17 % 10 = 3 in Python
            remainder = x % 10;
            // INT_MAX = 2147483647 INT_MIN = -2147483648
            if (ans > upper || (ans == upper && remainder > 7)) return 0;
            if (ans < lower || (ans == lower && remainder < -8)) return 0;
            ans = ans * 10 + remainder;
            x /= 10;
        }
        return ans;
    }
};

int main(int argc, char const *argv[]) {
    Solution s = Solution();
    cout << s.reverse(-123);
    return 0;
}