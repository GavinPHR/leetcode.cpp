class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>> ans;
        bool inserted = false;
        for (auto &interval : intervals) {
            int a = interval[0], b = interval[1];
            if (b < newInterval[0]) {
                ans.push_back(vector<int> {a, b});
            } else if (a > newInterval[1]) {
                if (!inserted) {
                    ans.push_back(newInterval);
                    inserted = true;
                }
                ans.push_back(vector<int> {a, b});
            } else {
                newInterval[0] = min(a, newInterval[0]);
                newInterval[1] = max(b, newInterval[1]);
            }
        }
        if (!inserted) ans.push_back(newInterval);
        return ans;
    }
};