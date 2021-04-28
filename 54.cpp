#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int l = 0, r = matrix[0].size() - 1;
        int t = 0, b = matrix.size() - 1;
        vector <int> ans;
        while (l <= r && t <= b) {
            for (int j = l; j <= r; ++j) {
                ans.push_back(matrix[t][j]);
            }
            for (int i = t + 1; i <= b; ++i) {
                ans.push_back(matrix[i][r]);
            }
            if (l < r && t < b) {
                for (int j = r - 1; j > l; --j) {
                    ans.push_back(matrix[b][j]);
                }
                for (int i = b; i > t; --i) {
                    ans.push_back(matrix[i][l]);
                }
            }
            ++t, ++l, --b, --r;
        }
        return ans;
    }
};

int main(int argc, char const *argv[])
{
    Solution s = Solution();
    vector<vector<int>> v = {vector<int>{1, 2, 3},
                             vector<int>{4, 5, 6},
                             vector<int>{7, 8, 9}};
    for (auto i: s.spiralOrder(v)) {
        cout << i << " ";
    }
    return 0;
}
