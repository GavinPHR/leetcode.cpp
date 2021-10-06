class Solution {
public:
    int compareVersion(string version1, string version2) {
        int n = version1.size(), m = version2.size();
        int i = 0 ,j = 0;
        while (i < n || j < m) {
            unsigned int x = 0;
            while (i < n && version1[i] != '.') {
                x = x * 10 + (version1[i] - '0');
                ++i;
            }
            unsigned int y = 0;
            while (j < m && version2[j] != '.') {
                y = y * 10 + (version2[j] - '0');
                ++j;
            }
            if (x > y) return 1;
            else if (x < y) return -1;
            ++i;
            ++j;
        }
        return 0;
    }
};