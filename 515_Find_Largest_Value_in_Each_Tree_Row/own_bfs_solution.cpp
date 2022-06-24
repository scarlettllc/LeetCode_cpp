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
    vector<int> largestValues(TreeNode* root) {
        if (root == nullptr) {
            return {};
        }
        queue<TreeNode*> q;
        q.emplace(root);
        vector<int> result;
        while (!q.empty()) {
            int sz = q.size();
            int max_val = INT_MIN;
            for (int i = 0; i < sz; ++i) {
                TreeNode* top = q.front();
                q.pop();
                max_val = max(max_val, top->val);
                if (top->left) {
                    q.emplace(top->left);
                }
                if (top->right) {
                    q.emplace(top->right);
                }
            }
            result.push_back(max_val);
        }
        return result;
    }
};