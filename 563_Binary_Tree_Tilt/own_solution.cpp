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
    int findTilt(TreeNode* root) {
        if (root == nullptr) {
            return 0;
        }
        vector<int> result = postorder(root);
        return result[2];
    }
    vector<int> postorder(TreeNode* root) {
        vector<int> result(3, 0), left_tree(3, 0), right_tree(3, 0);
        if (root->left != nullptr) {
            left_tree = postorder(root->left);
            result[0] = left_tree[0] + left_tree[1] + root->left->val;
        }
        if (root->right != nullptr) {
            right_tree = postorder(root->right);
            result[1] = right_tree[0] + right_tree[1] + root->right->val;
        }
        result[2] = left_tree[2] + right_tree[2] + abs(result[0] - result[1]);
        return result;
    }
};