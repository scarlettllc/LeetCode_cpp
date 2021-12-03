class Solution {
public:
    int largestSumAfterKNegations(vector<int>& nums, int k) {
        for (int i = 0; i < k; ++i) {
            int minPosition = min_element(nums.begin(), nums.end()) - nums.begin();
            nums[minPosition] = -nums[minPosition];
        }
        return accumulate(nums.begin(), nums.end(), 0);
    }
};