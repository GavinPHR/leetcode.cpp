class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        vector<int> stack;
        int a, b, c;
        for (auto t : tokens) {
            // for (auto s : stack) cout << s << " ";
            // cout << endl;
            if (t == "+") {
                b = stack.back(); stack.pop_back();
                a = stack.back(); stack.pop_back();
                c = a + b;
            } else if (t == "-") {
                b = stack.back(); stack.pop_back();
                a = stack.back(); stack.pop_back();
                c = a - b;
            } else if (t == "*") {
                b = stack.back(); stack.pop_back();
                a = stack.back(); stack.pop_back();
                c = a * b;
            } else if (t == "/") {
                b = stack.back(); stack.pop_back();
                a = stack.back(); stack.pop_back();
                c = a / b;
            } else {
                c = stoi(t);
            }
            stack.push_back(c);
        }
        return stack.back();
    }
};