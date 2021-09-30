class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        vector<int> heights_guarded(heights.size() + 2, 0);
        for (int i = 0; i < heights.size(); ++i) {
            heights_guarded[i + 1] = heights[i];
        }
        vector<int> stack;
        int ans = 0;
        for (int i = 0; i < heights_guarded.size(); ++i) {
            while (!stack.empty() && heights_guarded[i] < heights_guarded[stack.back()]) {
                int j = stack.back();
                stack.pop_back();
                ans = max(ans, (i - stack.back() - 1) * heights_guarded[j]);
            }
            stack.push_back(i);
        }
        return ans;
    }
};