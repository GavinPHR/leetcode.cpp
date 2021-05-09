class Solution {
public:
    void fold(char &op, vector<int> &nums) {
        int a = nums.back();
        nums.pop_back();
        if (op == '+') {
            nums.back() += a;
        } else if (op == '-') {
            nums.back() -= a;
        }
    }
    void print(vector<char> ops, vector<int> nums) {
        for (auto c : ops) cout << c << " ";
        cout << endl;
        for (auto c: nums) cout << c << " ";
        cout << endl;
    }
    int calculate(string s) {
        vector<char> ops;
        vector<int> nums;
        // Make all ops binary
        int i = 0;
        int n = 0;
        if (s[0] == '+' || s[0] == '-') nums.push_back(0);
        while (i < s.size()) {
            // print(ops, nums);
            char &c = s[i];
            if (isdigit(c)) {
                while (isdigit(s[i])) {
                    n = n * 10 + (s[i] - '0');
                    ++i;
                }
                nums.push_back(n);
                n = 0;
                if (!ops.empty() && ops.back() != '(') {
                    fold(ops.back(), nums);
                    ops.pop_back();
                }
                --i;
            } else if (c == '(') {
                ops.push_back('(');
                if (s[i + 1] == '+' || s[i + 1] == '-') {
                    nums.push_back(0);
                }
            } else if (c == ')') {
                ops.pop_back();
                while (!ops.empty() && ops.back() != '('){
                    fold(ops.back(), nums);
                    ops.pop_back();
                }
            } else if (c != ' ') {
                ops.push_back(c);
            }
            ++i;
        }
        return nums.back();
    }
};
