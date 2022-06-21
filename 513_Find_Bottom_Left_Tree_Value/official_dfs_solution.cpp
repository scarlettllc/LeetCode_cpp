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
        int curval, curheight = 0;
        dfs(root, 0, curval, curheight);
        return curval;
    }
    void dfs(TreeNode* root, int height, int& curval, int& curheight) {
        if (root == nullptr) {
            return;
        }
        ++height;
        dfs(root->left, height, curval, curheight);
        dfs(root->right, height, curval, curheight);
        if (height > curheight) {
            curval = root->val;
            curheight = height;
        }
    }
};