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
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> result;
        stack<TreeNode*> s;
        s.push(root);
        while (!s.empty()) {
            TreeNode* top = s.top();
            s.pop();
            if (top) {
                result.push_back(top->val);
            } else {
                continue;
            }
            s.push(top->left);
            s.push(top->right);
        }
        reverse(result.begin(), result.end());
        return result;
    }
};