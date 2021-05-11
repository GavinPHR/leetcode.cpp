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
    int best = INT_MIN;

    int dfs(TreeNode *node) {
        if (node == nullptr) return 0;
        int left = dfs(node->left);
        int right = dfs(node->right);
        best = max(best, left + right + node->val);
        // this is similar to maximum subarray
        int one_side_best = max(max(left, right) + node->val, node->val);
        best = max(best, one_side_best);
        return one_side_best;
    }

    int maxPathSum(TreeNode* root) {
        dfs(root);
        return best;
    }
};
