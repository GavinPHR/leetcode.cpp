#include <vector>
#include <iostream>

using namespace std;

// fibonacci can be solved in log(n) with math
class Solution {
public:
    int climbStairs(int n) {
        int a = 0, b = 1, c;
        while (n != 0) {
            c = a + b;
            a = b;
            b = c;
            --n;
        }
        return c;
    }
};

int main(int argc, char const *argv[])
{
    Solution s = Solution();
    cout << s.climbStairs(45);
    return 0;
}