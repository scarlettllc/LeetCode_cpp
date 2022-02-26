class Solution {
public:
    int maximumDifference(vector<int>& nums) {
        int result = -1, n = nums.size();
        vector<int> min_nums(n, nums[0]);
        vector<int> max_nums(n, nums[n - 1]);
        for (int i = 1; i < n; ++i) {
            min_nums[i] = min(min_nums[i - 1], nums[i]);
        }
        for (int i = n - 2; i >= 0; --i) {
            max_nums[i] = max(max_nums[i + 1], nums[i]);
        }
        for (int i = 0; i < n - 1; ++i) {
            result = max(result, max_nums[i + 1] - min_nums[i]);
        }
        return result == 0? -1 : result;
    }
};