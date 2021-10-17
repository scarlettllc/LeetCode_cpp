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
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> result;
        stack<TreeNode*> s;
        if (root) {
            s.push(root);
            TreeNode* temp = root;
            while (temp->left) {
                s.push(temp->left);
                temp = temp->left;
            }
        }
        while (!s.empty()) {
            TreeNode* top = s.top();
            s.pop();
            result.push_back(top->val);
            if (top->right) {
                s.push(top->right);
                TreeNode* temp = top->right;
                while (temp->left) {
                    s.push(temp->left);
                    temp = temp->left;
                }
            }
        }
        return result;
    }
};