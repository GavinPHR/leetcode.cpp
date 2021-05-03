class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int m = grid.size(), n = grid[0].size();
        int ans = 0;
        int directions[] = {1, 0, -1, 0, 1};
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == '2' || grid[i][j] == '0') continue;
                ++ans;
                vector<int> stacki{i}, stackj{j};
                while (!stacki.empty()) {
                    int a = stacki.back(), b = stackj.back();
                    stacki.pop_back();
                    stackj.pop_back();
                    if (grid[a][b] == '2') continue;
                    grid[a][b] = '2';
                    for (int k = 0; k < 4; ++k) {
                        int new_a = a + directions[k], new_b = b + directions[k + 1];
                        if (new_a >= 0 && new_b >= 0 && 
                            new_a < m && new_b < n && 
                            grid[new_a][new_b] == '1') {
                            stacki.push_back(new_a);
                            stackj.push_back(new_b);
                        }
                    }
                }
            }
        }
        return ans;
    }
};