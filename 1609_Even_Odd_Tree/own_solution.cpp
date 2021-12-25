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
    bool isEvenOddTree(TreeNode* root) {
        int height = dfs(root);
        vector<vector<int>> elements(height, vector<int>());
        queue<pair<TreeNode*, int>> q;
        q.push({root, 0});
        while (!q.empty()) {
            auto top = q.front();
            q.pop();
            elements[top.second].push_back(top.first->val);
            if (top.first->left != nullptr) {
                q.push({top.first->left, top.second + 1});
            } 
            if (top.first->right != nullptr) {
                q.push({top.first->right, top.second + 1});
            }
        }
        for (int i = 0; i < height; ++i) {
            if (i % 2 == 0) {
                for (int j = 0; j < elements[i].size(); ++j) {
                    if (elements[i][j] % 2 == 0) {
                        return false;
                    }
                }
                vector<int> temp = elements[i];
                sort(temp.begin(), temp.end());
                temp.erase(unique(temp.begin(), temp.end()), temp.end());
                if (temp != elements[i]) {
                    return false;
                }
            } else {
                for (int j = 0; j < elements[i].size(); ++j) {
                    if (elements[i][j] % 2 != 0) {
                        return false;
                    }
                }
                vector<int> temp = elements[i];
                sort(temp.begin(), temp.end(), greater<int>());
                temp.erase(unique(temp.begin(), temp.end()), temp.end());
                if (temp != elements[i]) {
                    return false;
                }
            }
        }
        return true;
    }
    int dfs(TreeNode* root) {
        if (root == nullptr) {
            return 0;
        } else {
            return 1 + max(dfs(root->left), dfs(root->right));
        }
    }
};