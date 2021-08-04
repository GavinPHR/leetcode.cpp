class Solution {
public:
    // void print(unordered_map<string, int> c) {
    //     for (auto &[k, v] : c) {
    //         cout << k << " " << v << endl;
    //     }
    //     cout << endl;
    // }

    vector<int> findSubstring(string s, vector<string>& words) {
        int d = words[0].size();
        if (s.size() < d) return {};
        int window_size = words.size() * d;
        unordered_map<string, int> baseline;
        for (auto word : words) {
            // if (baseline.find(word) != baseline.end()) {
            ++baseline[word];
            // } else {
            //     baseline[word] = 1;
            // }
        }
        // print(baseline);
        vector<int> ans;
        vector<unordered_map<string, int>> counters(d);
        for (int i = 0; i < d && i + window_size <= s.size(); ++i) {
            for (int j = i; j < i + window_size; j += d) {
                ++counters[i][s.substr(j, d)];
            }
            if (counters[i] == baseline) ans.push_back(i);
        }
        // for (auto m : counters) print(m);
        for (int i = 0; i + window_size + d <= s.size(); ++i) {
            int cnt_i = i % d;
            if (--counters[cnt_i][s.substr(i, d)] == 0) counters[cnt_i].erase(s.substr(i, d));
            ++counters[cnt_i][s.substr(i + window_size, d)];
            if (counters[cnt_i] == baseline) ans.push_back(i + d);
            // cout << i << " " << cnt_i << endl;
            // print(counters[cnt_i]);
        }
        return ans;



    }
};