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
    int res = 0;
    void sumNumbers_(TreeNode* root, int carry) {
        int k = carry * 10 + root->val;
        if (!root->left && !root->right) {
            res += k;
            return;
        }
        if (root->left) sumNumbers_(root->left, k);
        if (root->right) sumNumbers_(root->right, k);
    }

    int sumNumbers(TreeNode* root) {
        if (!root) return 0;
        res = 0;
        sumNumbers_(root, 0);
        return res;
    }  
};