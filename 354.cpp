class Solution {
public:
    int maxEnvelopes(vector<vector<int>>& envelopes) {
        sort(envelopes.begin(), envelopes.end(), [](vector<int> &a, vector<int> &b) {return a[0] == b[0] ? b[1] < a[1] : a[0] < b[0];});
        vector<int> LIS(envelopes.size(), 0);
        int i = 0;
        for (auto env : envelopes) {
            int a = env[0], b = env[1];
            int l = 0, r = i - 1;
            while (l < r) {
                int mid = l + (r - l) / 2;
                if (LIS[mid] < b) {
                    l = mid + 1;
                } else {
                    r = mid;
                }
            }
            if (LIS[l] >= b) {
                LIS[l] = b;
            } else {
                LIS[i++] = b;
            }
        }
        return i;
    }
};