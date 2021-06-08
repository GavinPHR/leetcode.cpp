class Solution {
public:
    /* jjjjjj
         iiii
    ---------
   zzzzzzzzzz   
     When you have 2 numbers of length m and n,
     the length of the product can be m + n or m + n - 1
     e.g. 150 * 1 = 150, 150 * 7 = 1050
    */
    string multiply(string num1, string num2) {
        if (num1 == "0" || num2 == "0") return "0";
        int m = num1.size(), n = num2.size();
        vector<int> res(m + n, 0);
        for (int i = num1.size() - 1; i >= 0; --i) {
            for (int j = num2.size() - 1; j >= 0; --j) {
                res[i + j + 1] += (num1[i] - '0') * (num2[j] - '0');
            } 
        }
        for (int i = res.size() - 1; i > 0; --i) {
            res[i - 1] += res[i] / 10;
            res[i] = res[i] % 10;
        }
        int i = res[0] != 0 ? 0 : 1;
        string ret = "";
        while (i < res.size()) {
            ret += res[i] + '0';
            ++i;
        } 
        return ret;
    }
};