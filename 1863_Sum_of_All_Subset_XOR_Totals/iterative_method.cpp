class Solution {
public:
    int subsetXORSum(vector<int>& nums) {
        int n = nums.size(), result = 0;
        for (int i = 0; i < (1 << n); ++i) {
            int temp = 0;
            for (int j = 0; j < n; ++j) {
                if (i & (1 << j)) {
                    temp ^= nums[j];
                }
            }
            result += temp;
        }
        return result;
    }
};