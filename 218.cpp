class Solution {
public:
    vector<vector<int>> getSkyline(vector<vector<int>>& buildings) {
        multiset<pair<int, int>> all;
        for (auto &b : buildings) {
            // Important the starting boundary is negative
            // and the ending boundary is positive:
            // 1. distinguish between start and end
            // 2. when the start of one coincides with the end of another, 
            // we want to process the start of the other first
            all.insert(make_pair(b[0], -b[2]));
            all.insert(make_pair(b[1], b[2]));
        }

        vector<vector<int>> res;
        multiset<int> heights = {0};
        vector<int> last = {0, 0};
        for (auto it = all.begin(); it != all.end(); ++it) {
            // cout << it->first << " " << it->second << endl;
            if (it->second < 0) heights.insert(-it->second);
            else heights.erase(heights.find(it->second)); // if erase(it->second), all the elements with same key are erased
            int height = *(heights.rbegin());
            // cout << height << endl;
            if (height != last[1]) {
                last[0] = it->first;
                last[1] = height;
                res.push_back(last); // last is lvalue, so copied
            }
            // cout << last[0] << " " << last[1] << endl;
            // cout << endl; 
        }
        return res;

    }
};