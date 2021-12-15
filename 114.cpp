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
    TreeNode* rec(TreeNode* root, TreeNode* remain) {
        if (!root->left && !root->right) {
            root->right = remain;
            return root;
        }
        TreeNode* right = remain;
        if (root->right) {
            right = rec(root->right, remain);
        }
        TreeNode* left = nullptr;
        if (root->left) {
            left = rec(root->left, right);
            root->right = left;
            root->left = nullptr;
        }
        return root;
    }

    void flatten(TreeNode* root) {
        if (!root) return;
        rec(root, nullptr);
    }
};