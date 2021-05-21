class Solution {
public:
    default_random_engine gen;
    uniform_int_distribution<int> distribution;
    unordered_map<int, int> map;
    Solution(int n, vector<int>& blacklist) {
        int size = blacklist.size();
        distribution = uniform_int_distribution<int>(0, n - 1 - size);
        int right = size - 1;
        // 0 1 x x 4 5 x 7
        // set = {5, 6, 7} => remove 6 => {5, 7} => map 2 to 5, 3 to 7
        unordered_set<int> set;
        for (int i = n - size; i < n; ++i) set.insert(i);
        for (auto i : blacklist) {
            if (set.find(i) != set.end()) set.erase(i);
        }
        auto it = set.begin();
        // while (it != set.end()) {
        //     cout << *it << endl;
        //     ++it;
        // }
        for (auto i : blacklist) {
            if (i < n - size) {
                map[i] = *it;
                ++it;
            }
        }
    }
    
    int pick() {
        int num = distribution(gen);
        if (map.find(num) != map.end()) return map[num];
        return num;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(n, blacklist);
 * int param_1 = obj->pick();
 */