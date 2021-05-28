class Solution {
public:
    // Brute-force using prefix sum array, n^2 TLE
    // int countRangeSum(vector<int>& nums, int lower, int upper) {
    //     vector<long long> prefix(nums.size());
    //     prefix[0] = nums[0];
    //     for (auto i = 1; i < nums.size(); ++i) {
    //         prefix[i] = prefix[i - 1] + nums[i];
    //     }

    //     long long ans = 0;
    //     auto in_range = [&](long long k){return k >= lower && k <= upper;};
    //     for (auto i = 0; i < prefix.size(); ++i) {
    //         if (in_range(prefix[i])) ++ans;
    //         for (auto j = 0; j < i; ++j) {
    //             if (in_range(prefix[i] - prefix[j])) ++ans;
    //         }
    //     }
    //     return ans;
    // }

    // Transform:
    // lower <= prefix[j] - prefix[i] <= upper
    // to:
    // prefix[j] - upper <= prefix[i] <= prefix[j] - lower
    // Then find the # of i that fits the requirement
    int countRangeSum(vector<int>& nums, int lower, int upper) {
        // prefix
        vector<long long> prefix(nums.size());
        prefix[0] = nums[0];
        for (int i = 1; i < prefix.size(); ++i) {
            prefix[i] = prefix[i - 1] + nums[i];
        }
        // discretize
        unordered_map<long long, int> map;
        // {
        unordered_set<long long> s(prefix.begin(), prefix.end());
        for (auto &n : prefix) {
            s.insert(n - upper);
            s.insert(n - lower);
        }
        s.insert(0);
        vector<long long> v(s.begin(), s.end());
        sort(v.begin(), v.end());
        for (int i = 0; i < v.size(); ++i) {
            map[v[i]] = i;
        } 
        // }
        // for (auto it = map.begin(); it != map.end(); ++it) cout << it->first << " " << it->second << endl;

        int res = 0;
        vector<int> tree(map.size(), 0);
        update(tree, map[0], 1);
        for (auto &n : prefix) {
            // for (auto &t : tree) cout << t << " ";
            // cout << endl;
            int right_prefix = prefix_sum(tree, map[n - lower]);
            int left_prefix = prefix_sum(tree, map[n - upper] - 1);
            // cout << right_prefix << " " << left_prefix << endl;
            res += right_prefix - left_prefix;
            // cout << res << endl;
            update(tree, map[n], 1);
        }
        return res;
    }

    int prefix_sum(vector<int> &tree, int k) {
        int res = 0;
        while (k >= 0) {
            res += tree[k];
            k &= k + 1;
            --k;
        }
        return res;
    }

    void update(vector<int> &tree, int k, int val) {
        while (k < tree.size()) {
            tree[k] += val;
            k |= k + 1;
        }
    }
};
