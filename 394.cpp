class Solution {
public:
    string decodeString(string s) {
        vector<string> sstack;
        vector<int> istack;
        int i = 0;
        while (i < s.size()) {
            int ord = s[i] - '0';
            int j = 0;
            while (ord >= 0 && ord <= 9) {
                ++j;
                ord = s[i + j] - '0';
            }
            if (j != 0) {
                istack.push_back(stoi(s.substr(i, j)));
                i += j;
                continue;
            }
            if (s[i] == ']') {
                string tmp = "";
                while (sstack.back() != "[") {
                    tmp = sstack.back() + tmp;
                    sstack.pop_back();
                }
                sstack.pop_back();
                string multiple = "";
                for (int n = 0; n < istack.back(); ++n) {
                    multiple += tmp;
                }
                istack.pop_back();
                sstack.push_back(multiple);
            } else {
                sstack.push_back(string(1, s[i]));
            }
            ++i;
        }
        string ret = "";
        for (auto &s : sstack) ret += s;
        return ret;
    }
};