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
    TreeNode *rec(int l, int r, int i, int j, vector<int> &pre, vector<int> &in, unordered_map<int, int> &map) {
        if (l > r) return nullptr;
        TreeNode *res = new TreeNode(pre[l]);
        if (l == r) return res;
        // cout << l << " " << r << " " << i << " " << j << endl;
        // cout << endl;
        int left = map[pre[l]] - i;
        res->left = rec(l + 1, l + left, i, map[pre[l]] - 1, pre, in, map);
        res->right = rec(l + left + 1, r, map[pre[l]] + 1, j, pre, in, map);
        return res;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        unordered_map<int, int> map;
        for (int i = 0; i < inorder.size(); ++i) {
            map[inorder[i]] = i;
        }
        return rec(0, preorder.size() - 1, 0, preorder.size() - 1, preorder, inorder, map);
    }
};