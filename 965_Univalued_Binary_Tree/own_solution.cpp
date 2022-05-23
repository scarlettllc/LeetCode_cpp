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
    bool isUnivalTree(TreeNode* root) {
        int val = root->val;
        return dfs(root->left, val) && dfs(root->right, val);
    }
    bool dfs(TreeNode* root, int val) {
        if (root == nullptr) {
            return true;
        }
        if (root->val != val) {
            return false;
        }
        return dfs(root->left, val) && dfs(root->right, val);
    }
};