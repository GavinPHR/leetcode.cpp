class Solution {
public:
    vector<vector<int>> ans;
    vector<int> buf;
    vector<int> cand;
    unordered_map<int, int> cnt;

    void rec(int cur, int remain) {
        if (remain < 0) {
            return;
        }
        if (remain == 0) {
            ans.push_back(vector<int>(buf));
            return;
        }
        if (cur == cand.size()) return;
        int n = cand[cur];
        int tot = cnt[n];
        rec(cur + 1, remain);
        for (int i = 0; i < tot; ++i) {
            buf.push_back(n);
            remain -= n;
            // for (auto k : buf) {
            //     cout << k << " ";
            // }
            // cout << remain;
            // cout << endl;
            rec(cur + 1, remain);
        }
        for (int i = 0; i < tot; ++i) {
            buf.pop_back();
            remain += n;
        }
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        for (auto i : candidates) {
            if (cnt.find(i) == cnt.end()) {
                cnt[i] = 1;
            } else {
                ++cnt[i];
            }
        }
        for (auto [k, v] : cnt) {
            cand.push_back(k);
        }
        sort(cand.begin(), cand.end());
        rec(0, target);
        return ans;
    }
};