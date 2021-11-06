class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int result = 0;
        int n = nums.size();
        for (int i = 0; i <= n; ++i) {
            result ^= i;
        }
        for (int i = 0; i < n; ++i) {
            result ^= nums[i];
        }
        return result;
    }
};