class Solution {
public:
    unordered_map<char, int> map = {{'I', 1},
                                    {'V', 5},
                                    {'X', 10},
                                    {'L', 50},
                                    {'C', 100},
                                    {'D', 500},
                                    {'M', 1000}};
    int romanToInt(string s) {
        int res = 0;
        int i = 0;
        while (i < s.size()) {
            if (i + 1 < s.size() && map[s[i + 1]] > map[s[i]]) {
                res -= map[s[i]];
                res += map[s[i + 1]];
                i += 2;
            } else {
                res += map[s[i]];
                ++i;
            }
        }
        return res;
    }
};