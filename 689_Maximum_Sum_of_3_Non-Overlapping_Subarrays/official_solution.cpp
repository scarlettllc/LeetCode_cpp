class Solution {
public:
    vector<int> maxSumOfThreeSubarrays(vector<int>& nums, int k) {
        vector<int> result;
        int sum1 = 0, maxSum1 = 0, maxSum1idx = 0;
        int sum2 = 0, maxSum12 = 0, maxSum12idx1 = 0, maxSum12idx2 = 0;
        int sum3 = 0, maxTotal = 0;
        for (int i = 2 * k; i < nums.size(); ++i) {
            sum1 += nums[i - 2 * k];
            sum2 += nums[i - k];
            sum3 += nums[i];
            if (i >= 3 * k - 1) {
                if (sum1 > maxSum1) {
                    maxSum1 = sum1;
                    maxSum1idx = i - 3 * k + 1;
                }
                if (maxSum1 + sum2 > maxSum12) {
                    maxSum12 = maxSum1 + sum2;
                    maxSum12idx1 = maxSum1idx;
                    maxSum12idx2 = i - 2 * k + 1;
                }
                if (maxSum12 + sum3 > maxTotal) {
                    maxTotal = maxSum12 + sum3;
                    result = {maxSum12idx1, maxSum12idx2, i - k + 1};
                }
                sum1 -= nums[i - 3 * k + 1];
                sum2 -= nums[i - 2 * k + 1];
                sum3 -= nums[i - k + 1];
            }
        }
        return result;
    }
};