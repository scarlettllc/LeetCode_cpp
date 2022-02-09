class Solution {
public:
    int countKDifference(vector<int>& nums, int k) {
        unordered_map<int, int> m;
        int result = 0;
        for (auto & num : nums) {
            ++m[num];
            result += m[num - k];
            result += m[num + k];
        }
        return result;
    }
};