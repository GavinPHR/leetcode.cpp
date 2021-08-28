class Solution {
public:
    vector<vector<int>> ans;
    vector<int> used;
    void rec(vector<int>& candidates, int target, int i) {
        if (target == 0) {
            ans.push_back(used);
            return;
        } 
        if (i == candidates.size() || target < 0) return;
        rec(candidates, target, i + 1);
        used.push_back(candidates[i]);
        rec(candidates, target - candidates[i], i);
        used.pop_back();
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        rec(candidates, target, 0);
        return ans;
    }
};