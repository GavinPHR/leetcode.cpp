class Solution {
public:
    // Greedy
    int minSwapsCouples(vector<int>& row) {
        unordered_map<int, int> index;
        for (int i = 0; i < row.size(); ++i) {
            index[row[i]] = i;
        }
        int res = 0;
        for (int i = 0; i < row.size(); i += 2) {
            if (row[i] % 2 == 0) {
                if (row[i + 1] != row[i] + 1) {
                    int tmp = row[i + 1];
                    swap(row[i + 1], row[index[row[i] + 1]]);
                    swap(index[tmp], index[row[i] + 1]);
                    ++res;
                }
            } else {
                if (row[i + 1] != row[i] - 1) {
                    int tmp = row[i + 1];
                    swap(row[i + 1], row[index[row[i] - 1]]);
                    swap(index[tmp], index[row[i] - 1]);
                    ++res;
                }
            }
        }
        return res;
    }

    
};