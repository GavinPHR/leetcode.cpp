class Solution {
public:
    string addStrings(string num1, string num2) {
        int n1 = num1.size() - 1, n2 = num2.size() - 1;
        int carry = 0;
        string ans = "";
        while (n1 > -1 || n2 > -1 || carry) {
            int a = n1 > -1 ? num1[n1--] - '0' : 0;
            int b = n2 > -1 ? num2[n2--] - '0' : 0;
            int res = a + b + carry;
            ans.push_back('0' + res % 10);
            carry = res / 10;
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};
