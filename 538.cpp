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
    int rec(TreeNode *node, int right_sum) {
        if (node->right) right_sum = rec(node->right, right_sum);
        node->val += right_sum;
        int res = node->val;
        if (node->left) res = rec(node->left, node->val);
        return res;
    }

    TreeNode* convertBST(TreeNode* root) {
        if (root) rec(root, 0);
        return root;
    }
};