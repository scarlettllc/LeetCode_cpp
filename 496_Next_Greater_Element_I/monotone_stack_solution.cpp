class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        vector<int> result;
        stack<int> st;
        unordered_map<int, int> m;
        for (int i = nums2.size() - 1; i >= 0; --i) {
            int num = nums2[i];
            while (!st.empty() && num >= st.top()) {
                st.pop();
            }
            m[num] = st.empty() ? -1 : st.top();
            st.push(num);
        }        
        for (int i = 0; i < nums1.size(); ++i) {
            result.push_back(m[nums1[i]]);
        }
        return result;
    }
};