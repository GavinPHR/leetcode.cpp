class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& T) {
        vector<int> ans(T.size(), 0);
        vector<pair<int, int>> stack;
        for (int i = T.size() - 1; i > -1; --i) {
            while (!stack.empty() && T[i] >= stack.back().first) {
                stack.pop_back();
            }
            ans[i] = stack.empty() ? 0 : stack.back().second - i;
            stack.push_back(make_pair(T[i], i));
        }
        return ans;
    }
};
