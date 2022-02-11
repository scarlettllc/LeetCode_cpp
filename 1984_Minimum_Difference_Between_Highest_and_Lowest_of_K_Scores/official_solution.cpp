class Solution {
public:
    int minimumDifference(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int result = INT_MAX;
        for (int i = k - 1; i < nums.size(); ++i) {
            result = min(result, nums[i] - nums[i - k + 1]);
        }
        return result;
    }
};