class Solution {
public:
    int candy(vector<int>& ratings) {
        vector<int> res(ratings.size());
        res[0] = 1;
        for (int i = 1; i < ratings.size(); ++i) {
            res[i] = ratings[i - 1] < ratings[i] ? res[i - 1] + 1 : 1;
        }
        for (int i = ratings.size() - 2; i >= 0; --i) {
            res[i] = max(res[i], ratings[i] > ratings[i + 1] ? res[i + 1] + 1 : 1);
        }
        int ret = 0;
        for (auto &r : res) ret += r;
        return ret;
    }
};
