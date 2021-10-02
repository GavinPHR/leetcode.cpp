class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        vector<unordered_set<char>> rows(9), cols(9), grids(9);
        for (int i = 0; i < 9; ++i) {
            for (int j = 0; j < 9; ++j) {
                char n = board[i][j];
                if (n == '.') continue;
                if (rows[i].find(n) != rows[i].end()) return false;
                rows[i].insert(n);
                if (cols[j].find(n) != cols[j].end()) return false;
                cols[j].insert(n);
                int g = 3 * (i / 3) + (j / 3);
                if (grids[g].find(n) != grids[g].end()) return false;
                grids[g].insert(n);
            }
        }
        return true;
    }
};