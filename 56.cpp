class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());
        vector<vector<int>> ans;
        int l = intervals[0][0], r = intervals[0][1];
        int i = 1;
        while (i < intervals.size()) {
            if (intervals[i][0] > r) {
                ans.push_back(vector<int>{l, r});
                l = intervals[i][0], r = intervals[i][1];
            } else {
                r = max(r, intervals[i][1]);
            }
            ++i;
        }
        ans.push_back(vector<int>{l, r});
        return ans;
    }
};