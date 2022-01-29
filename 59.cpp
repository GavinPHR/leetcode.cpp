class Solution {
public:
    bool check(int i, int j, vector<vector<int>> &matrix, int n) {
        if (i >= n || j >= n || i < 0 || j < 0) return false;
        if (matrix[i][j] != 0) return false;
        return true; 
    }

    vector<vector<int>> generateMatrix(int n) {
        vector<pair<int, int>> directions = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
        vector<vector<int>> matrix(n, vector<int>(n, 0));
        matrix[0][0] = 1;
        int cur_num = 2;
        int cur_d = 0;
        int cur_i = 0, cur_j = 0;
        int new_i, new_j;
        while (1) {
            new_i = cur_i + directions[cur_d].first; 
            new_j = cur_j + directions[cur_d].second;
            if (!check(new_i, new_j, matrix, n)) {
                cur_d = (cur_d + 1) % 4;
                new_i = cur_i + directions[cur_d].first; 
                new_j = cur_j + directions[cur_d].second; 
            }
            // cout << new_i << " " << new_j << endl;
            if (!check(new_i, new_j, matrix, n)) break;
            matrix[new_i][new_j] = cur_num;
            cur_num += 1;
            cur_i = new_i; cur_j = new_j;
        }
        return matrix;
    }
};