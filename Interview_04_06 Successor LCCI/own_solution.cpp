/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* inorderSuccessor(TreeNode* root, TreeNode* p) {
        vector<TreeNode*> result;
        inOrder(root, result);
        for (int i = 0; i < result.size(); ++i) {
            if (result[i]->val == p->val) {
                if (i < result.size() - 1) {
                    return result[i + 1];
                } else {
                    return nullptr;
                }
            }
        }
        return nullptr;
    }
    void inOrder(TreeNode* root, vector<TreeNode*>& result) {
        if (root == nullptr) {
            return;
        }
        inOrder(root->left, result);
        result.push_back(root);
        inOrder(root->right, result);
    }
};