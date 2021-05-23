/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<TreeNode*> nodes;
    
    void inorder(TreeNode* node) {
        if (!node) return;
        inorder(node->left);
        nodes.push_back(node);
        inorder(node->right);
    }

    TreeNode* makeBinary(int i, int j) {
        if (i == j) {
            nodes[i]->left = nullptr;
            nodes[i]->right = nullptr;
            return nodes[i];
        }
        int mid = i + (j - i) / 2;
        TreeNode *left, *right;
        if (i == mid) left = nullptr;
        else left = makeBinary(i, mid - 1);
        right = makeBinary(mid + 1, j);
        nodes[mid]->left = left;
        nodes[mid]->right = right;
        return nodes[mid];
    }

    TreeNode* balanceBST(TreeNode* root) {
        if (!root) return root;
        inorder(root);
        return makeBinary(0, nodes.size() - 1);
    }
};