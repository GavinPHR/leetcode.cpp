class Solution {
public:
    string convert(string s, int numRows) {
        if (numRows == 1) return s;
        vector<string> rows(numRows);
        int direction = 1;
        int index = 0;
        for (auto &c : s) {
            rows[index].push_back(c);
            int cand = index + direction;
            if (cand == -1 || cand == numRows) {
                direction = -direction;
            }
            index += direction;
        }
        string ans = "";
        for (auto &sub : rows) ans += sub;
        return ans;
    }
};