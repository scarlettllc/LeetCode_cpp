/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    vector<vector<int>> levelOrder(Node* root) {
        if (root == nullptr) {
            return {};
        }
        vector<vector<int>> result;
        queue<Node*> q;
        q.emplace(root);
        while (!q.empty()) {
            int sz = q.size();
            vector<int> temp_result;
            for (int i = 0; i < sz; ++i) {
                Node* top = q.front();
                q.pop();
                temp_result.push_back(top->val);
                for (auto & child : top->children) {
                    q.emplace(child);
                }
            }
            result.push_back(temp_result);
        }
        return result;
    }
};