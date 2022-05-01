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
    vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {
        vector<int> result, result1, result2;
        inOrder(root1, result1);
        inOrder(root2, result2);
        int p1 = 0, p2 = 0, n1 = result1.size(), n2 = result2.size();
        while (p1 < n1 && p2 < n2) {
            if (result1[p1] <= result2[p2]) {
                result.push_back(result1[p1++]);
            } else {
                result.push_back(result2[p2++]);   
            }
        }
        while (p1 < n1) {
            result.push_back(result1[p1++]);
        }
        while (p2 < n2) {
            result.push_back(result2[p2++]);
        }
        return result;
    }
    void inOrder(TreeNode* root, vector<int>& result) {
        if (root == nullptr) {
            return;
        }
        inOrder(root->left, result);
        result.push_back(root->val);
        inOrder(root->right, result);
    }
};