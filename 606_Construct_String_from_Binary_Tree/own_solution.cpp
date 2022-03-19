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
    string tree2str(TreeNode* root) {
        string result = "";
        dfs(root, result);
        return result;
    }
    void dfs(TreeNode* root, string& result) {
        if (root == nullptr) {
            return;
        }
        result += to_string(root->val);
        if (root->left != nullptr || root->right != nullptr) {
            result += "(";
        }
        if (root->left != nullptr) {
            dfs(root->left, result);
        }
        if (root->left != nullptr || root->right != nullptr) {
            result += ")";
        }
        if (root->right != nullptr) {
            result += "(";
            dfs(root->right, result);
            result += ")";
        }
    }
};