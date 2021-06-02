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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        if (!root) return {};
        vector<TreeNode*> stack1, stack2;
        stack1.push_back(root);
        vector<vector<int>> res;
        while (!stack1.empty() || !stack2.empty()) {
            vector<int> tmp;
            while (!stack1.empty()) {
                TreeNode *node = stack1.back();
                stack1.pop_back();
                tmp.push_back(node->val);
                if (node->left) stack2.push_back(node->left);
                if (node->right) stack2.push_back(node->right);
            }
            if (!tmp.empty()) res.push_back(tmp);
            tmp.clear();
            while (!stack2.empty()) {
                TreeNode *node = stack2.back();
                stack2.pop_back();
                tmp.push_back(node->val);
                if (node->right) stack1.push_back(node->right);
                if (node->left) stack1.push_back(node->left);
            }
            if (!tmp.empty()) res.push_back(tmp);
        }
        return res;
    }
};