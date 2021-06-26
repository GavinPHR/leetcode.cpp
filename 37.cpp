// should come back and do it after learning bitset
class Solution {
public:
    unordered_map<int, unordered_set<int>> cols, rows, boxes;

    inline int getBox(int row, int col) {
        return (row / 3) * 3 + (col / 3);
    }

    inline pair<int, int> next(vector<vector<char>> &board, int row, int col) {
        while (col < 9) {
            if (col == 8) {
                col = 0;
                ++row;
                if (row == 9) return {-1, -1};
            } else {
                ++col;
            }
            if (board[row][col] == '.') return {row, col};
        }
        return {-2, -2}; // should never reach, for debugging purposes
    }

    bool rec(vector<vector<char>> &board, int row, int col) {
        for (int k = 1; k <= 9; ++k) {
            if (rows[row].find(k) != rows[row].end()) continue;
            if (cols[col].find(k) != cols[col].end()) continue;
            int box = getBox(row, col);
            if (boxes[box].find(k) != boxes[box].end()) continue;
            rows[row].insert(k);
            cols[col].insert(k);
            boxes[box].insert(k);
            board[row][col] = '0' + k;
            auto [nrow, ncol] = next(board, row, col);
            if (nrow == -1) return true;
            if (rec(board, nrow, ncol)) return true;
            board[row][col] = '.';
            rows[row].erase(k);
            cols[col].erase(k);
            boxes[box].erase(k);
        }
        return false; // should not reach here
    }

    void print(unordered_map<int, unordered_set<int>> ks) {
        for (int k = 0; k < 9; ++k) {
            if (ks.find(k) == ks.end()) continue;
            for (auto &i : ks[k]) {
                cout << i << " ";
            }
            cout << endl;
        }
    }

    void solveSudoku(vector<vector<char>>& board) {
        auto [row, col] = next(board, 0, -1);
        if (row == -1) return;
        for (int i = 0; i < 9; ++i) {
            for (int j = 0; j < 9; ++j) {
                if (board[i][j] != '.') {
                    int n = board[i][j] - '0';
                    rows[i].insert(n);
                    cols[j].insert(n);
                    boxes[getBox(i, j)].insert(n);
                }
            }
        }
        // print(rows);
        // print(cols);
        // print(boxes);
        bool success = rec(board, row, col);
        if (!success) cout << "unsuccessful" << endl;
        return;
    }
};