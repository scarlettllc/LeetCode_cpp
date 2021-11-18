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
    int result = 0;
    int findTilt(TreeNode* root) {
        dfs(root);
        return result;
    }
    int dfs(TreeNode* root) {
        if (root == nullptr) {
            return 0;
        }
        int left_sum = dfs(root->left);
        int right_sum = dfs(root->right);
        result += abs(left_sum - right_sum);
        return left_sum + right_sum + root->val;
    }
};