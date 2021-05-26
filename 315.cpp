// https://cp-algorithms.com/data_structures/fenwick.html
class Solution {
public:
    // index k is the sum of [g(k)..k]
    inline int g(int k) {
        return k & (k + 1);
    }

    // iteratively used to find all i where g(i) <= k <= i
    inline int h(int k) {
        return k | (k + 1);
    }

    int prefix_sum(vector<int> &tree, int k) {
        int res = 0;
        while (k >= 0) {
            res += tree[k];
            k = g(k) - 1;
        }
        return res;
    }

    // add val to index k
    void add(vector<int> &tree, int k, int val) {
        while (k < tree.size()) {
            ++tree[k];
            k = h(k);
        }
    }

    // change to prefix sum problem, using binary indexed tree
    vector<int> countSmaller(vector<int>& nums) {
        // discretize
        unordered_set<int> s(nums.begin(), nums.end());
        vector<int> v(s.begin(), s.end());
        sort(v.begin(), v.end());
        unordered_map<int, int> map;
        for (int i = 0; i < v.size(); ++i) {
            map[v[i]] = i;
        }
        
        vector<int> res(nums.size());
        // Binary indexed tree
        vector<int> tree(map.size(), 0);
        for (int i = nums.size() - 1; i > -1; --i) {
            int n = map[nums[i]];
            res[i] = prefix_sum(tree, n - 1);
            add(tree, n, 1);
        }
        return res;
    }
};