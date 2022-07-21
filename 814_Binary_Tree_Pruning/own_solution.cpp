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
    TreeNode* pruneTree(TreeNode* root) {
        bool result = dfs(root);
        return result ?  root : nullptr;
    }
    bool dfs(TreeNode* root) {
        if (root == nullptr) {
            return false;
        }
        bool left = dfs(root->left);
        bool right = dfs(root->right);
        if (!left) {
            root->left = nullptr;
        }
        if (!right) {
            root->right = nullptr;
        }
        if (root->left == nullptr && root->right == nullptr) {
            if (root->val == 0) {
                root = nullptr;
                return false;
            } else {
                return true;
            }
        }
        if (left || right || root->val == 1) {
            return true;
        }
        return true;
    }
};