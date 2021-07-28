
class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        if (!root) return {};
        int known_height = 0;
        vector<pair<int, TreeNode*>> stack = {make_pair(1, root)};
        vector<int> ans;
        while (!stack.empty()) {
            auto [height, node] = stack.back();
            // cout << node->val << endl;
            if (height > known_height) {
                ans.push_back(node->val);
                known_height = height;
            }
            stack.pop_back();
            // if (node->left) cout << node->left->val << endl;
            // if (node->right) cout << node->right->val << endl;
            if (node->left) stack.push_back(make_pair(height + 1, node->left));
            if (node->right) stack.push_back(make_pair(height + 1, node->right));
        }
        return ans;
    }
};