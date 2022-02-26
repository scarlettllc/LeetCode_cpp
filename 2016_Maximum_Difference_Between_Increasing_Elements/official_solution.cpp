class Solution {
public:
    int maximumDifference(vector<int>& nums) {
        int result = -1, n = nums.size(), premin = nums[0];
        for (int i = 1; i < n; ++i) {
            if (nums[i] > premin) {
                result = max(result, nums[i] - premin);
            } else {
                premin = nums[i];
            }
        }
        return result;
    }
};