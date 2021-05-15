class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char, int> count;
        for (auto &c : t) {
            if (count.find(c) == count.end()) count[c] = 0;
            ++count[c];
        }
        int entries = count.size();

        int left = 0;
        int ans_start;
        int ans_size = INT_MAX;
        for (int right = 0; right < s.size();) {
            if (count.find(s[right]) != count.end()) {
                --count[s[right]];
                if (count[s[right]] == 0) --entries;
            }
            ++right;
            // If all characters matched, decrease left boundary as much as possible
            if (entries == 0) {
                while (entries == 0) {
                    if (count.find(s[left]) != count.end()) {
                        ++count[s[left]];
                        if (count[s[left]] == 1) ++entries;
                    } 
                    ++left;
                }
                int tmp_size = right - left + 1;
                if (tmp_size < ans_size) {
                    ans_size = tmp_size;
                    ans_start = left - 1;
                }
            }
        }
        if (ans_size == INT_MAX) return "";
        return s.substr(ans_start, ans_size);
    }
};