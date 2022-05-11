/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string result = "";
        if (root == nullptr) {
            return result;
        }
        vector<int> nums;
        post_order(root, nums);
        for (int i = 0; i < nums.size() - 1; ++i) {
            result += to_string(nums[i]) + ',';
        }
        result += to_string(nums.back());
        return result;
    }
    void post_order(TreeNode* root, vector<int>& nums) {
        if (root == nullptr) {
            return;
        }
        post_order(root->left, nums);
        post_order(root->right, nums);
        nums.push_back(root->val);
        return;
    }
    vector<int> split(string data, char c) {
        vector<int> result;
        int n = data.size(), i = 0, j;
        while (i < n) {
            while (i < n && data[i] == c) {
                ++i;
            }
            j = i;
            while (i < n && data[i] != c) {
                ++i;
            }
            result.push_back(stoi(data.substr(j, i - j)));
        } 
        return result;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if (data.size() == 0) {
            return nullptr;
        }
        vector<int> nums = split(data, ',');
        stack<int> st;
        for (auto & num : nums) {
            st.emplace(num);
        }
        return construct(INT_MIN, INT_MAX, st);
    }
    TreeNode* construct(int lower, int upper, stack<int>& st) {
        if (st.size() == 0 || st.top() < lower || st.top() > upper) {
            return nullptr;
        }
        int val = st.top();
        st.pop();
        TreeNode* root = new TreeNode(val);
        root->right = construct(val, upper, st);
        root->left = construct(lower, val, st);
        return root; 
    }
};

// Your Codec object will be instantiated and called as such:
// Codec* ser = new Codec();
// Codec* deser = new Codec();
// string tree = ser->serialize(root);
// TreeNode* ans = deser->deserialize(tree);
// return ans;