class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        vector<int> result(nums1.size(), -1);
        unordered_map<int, int> m;
        int i, j;
        for (i = 0; i < nums2.size(); ++i) {
            bool flag = false;
            for (j = i + 1; j < nums2.size(); ++j) {
                if (nums2[j] > nums2[i]) {
                    flag = true;
                    break;
                }
            }
            if (flag) {
                m[nums2[i]] = nums2[j];
            } else {
                m[nums2[i]] = -1;
            }
        }
        for (int i = 0; i < nums1.size(); ++i) {
            result[i] = m[nums1[i]];
        }
        return result;
    }
};