class Solution {
public:
    int subsetXORSum(vector<int>& nums) {
        int n = nums.size(), result = 0;
        for (auto & num : nums) {
            result |= num;
        }
        return result << (n - 1);
    }
};