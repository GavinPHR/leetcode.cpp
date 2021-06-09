/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        if (!root) return {};
        deque<pair<TreeNode*, int>> q{make_pair(root, 0)};
        vector<vector<int>> res;
        vector<int> tmp;
        int cur = 0;
        while (!q.empty()) {
            auto [node, level] = q.front();
            q.pop_front();
            if (level != cur) {
                cur = level;
                res.push_back(tmp);
                tmp.clear();
            }
            tmp.push_back(node->val);
            if (node->left) q.push_back(make_pair(node->left, level + 1));
            if (node->right) q.push_back(make_pair(node->right, level + 1));
        }
        res.push_back(tmp);
        return res;
    }
};