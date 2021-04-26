#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

void print2D(vector<vector<int>> a, int size1, int size2) {
    for (int i = 0; i <= size1; ++i) {
        for (int j = 0; j <= size2; ++j) {
            cout << a[i][j] << " ";
        }
        cout << endl;
    }
}

class Solution {
public:
    int minDistance(string word1, string word2) {
        int m = word1.size(), n = word2.size();
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0)); 
        // base caes
        for (int i = 0; i <= m; ++i) {
            dp[i][0] = i;
        }
        for (int j = 0; j <= n; ++j) {
            dp[0][j] = j;
        }
        for (int i = 1; i <= m; ++i) {
            for (int j = 1; j <= n; ++j) {           
                dp[i][j] = min(min(dp[i - 1][j],
                                   dp[i][j - 1]) + 1,
                                   dp[i - 1][j - 1] + (word1[i - 1] == word2[j - 1] ? 0 : 1));
            }
        } 
        // print2D(dp, m, n);
        return dp[m][n];
    }
};


int main(int argc, char const *argv[])
{
    Solution s = Solution();
    // cout << s.minDistance("horse", "ros") << endl;
    // cout << s.minDistance("intention", "execution") << endl;
    cout << s.minDistance("zoologicoarchaeologist", "zoogeologist") << endl;
    return 0;
}
