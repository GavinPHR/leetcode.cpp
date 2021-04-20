#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int size1 = nums1.size(), size2 = nums2.size();
        int k = (size1 + size2) / 2;
        int half, half1, half2;
        int n1 = -1, n2 = -1;
        while (k && n1 != size1 - 1 && n2 != size2 - 1) {
            half = k / 2 == 0 ? 1 : k / 2;
            half1 = min(half, size1 - 1 - n1);
            half2 = min(half, size2 - 1 - n2);
            if (nums1[n1 + half1] < nums2[n2 + half2]) {
                n1 += half1;
                k -= half1;
            } else {
                n2 += half2;
                k -= half2;
            }
            cout << n1 << " " << n2 << "\n";
        }
        if (k) {
            if (n1 != size1 - 1) {
                n1 += k;
            } else {
                n2 += k;
            }
        }
        int right = n1 + 1 < size1 ? nums1[n1 + 1] : INT_MAX;
        right = min(n2 + 1 < size2 ? nums2[n2 + 1] : INT_MAX, right);
        if ((size1 + size2) % 2 == 0) {
            int left;
            if (n1 == -1) {
                left = nums2[n2];
            } else if (n2 == -1) {
                left = nums1[n1];
            } else {
                left = nums1[n1] > nums2[n2] ? nums1[n1] : nums2[n2];
            }
            return ((double) left + right) / 2;
        } else {
            return (double) right;
        }
        return 0.0;
    }
};

int main(int argc, char const *argv[]) {
    Solution s = Solution();
    vector<int> a, b;
    // a = {1, 3}, b = {2};
    // cout << s.findMedianSortedArrays(a, b) << "\n";
    // a = {1, 2}, b = {3, 4};
    // cout << s.findMedianSortedArrays(a, b) << "\n";
    // a = {0, 0}, b = {0, 0};
    // cout << s.findMedianSortedArrays(a, b) << "\n";
    // a = {}, b = {1};
    // cout << s.findMedianSortedArrays(a, b) << "\n";
    a = {1, 2}, b = {-1, 3};
    cout << s.findMedianSortedArrays(a, b) << "\n";
    return 0;
}
