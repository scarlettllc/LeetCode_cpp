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
    int findBottomLeftValue(TreeNode* root) {
        queue<TreeNode*> q;
        int result;
        q.emplace(root);
        while (!q.empty()) {
            TreeNode *top = q.front();
            q.pop();
            if (top->right) {
                q.emplace(top->right);
            }
            if (top->left) {
                q.emplace(top->left);
            }
            result = top->val;
        }
        return result;
    }
};