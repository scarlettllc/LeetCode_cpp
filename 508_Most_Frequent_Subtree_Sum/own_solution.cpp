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
private:
    unordered_map<int, int> m;
public:
    vector<int> findFrequentTreeSum(TreeNode* root) {
        helper(root);
        int max_cnt = 0;
        for (auto & [sum, cnt] : m) {
            if (cnt > max_cnt) {
                 max_cnt = cnt;
            }
        }
        vector<int> result;
        for (auto & [sum, cnt] : m) {
            if (cnt == max_cnt) {
                result.push_back(sum);
            }
        }
        return result;
    }
    int helper(TreeNode* root) {
        if (root == nullptr) {
            return 0;
        }
        int left = helper(root->left);
        int right = helper(root->right);
        int total = root->val + left + right;
        ++m[total];
        return total;
    }
};