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
        vector<int> result;
        dfs(root, result, 0);
        return result;
    }
    void dfs(TreeNode* root, vector<int>& result, int curheight) {
        if (result.size() == curheight) {
            result.push_back(root->val);
        } else {
            result[curheight] = max(result[curheight], root->val);
        }
        if (root->left) {
            dfs(root->left, result, curheight + 1);
        }
        if (root->right) {
            dfs(root->right, result, curheight + 1);
        }
    }
};