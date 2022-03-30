class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int n = nums.size(), result = 0;
        int left = 0, lsum = 0, rsum = 0;
        for (int right = 0; right < n; ++right) {
            rsum += 1 - nums[right];
            while (lsum < rsum - k) {
                lsum += 1 - nums[left];
                ++left;
            }
            result = max(result, right - left + 1);
        }
        return result;
    }
};