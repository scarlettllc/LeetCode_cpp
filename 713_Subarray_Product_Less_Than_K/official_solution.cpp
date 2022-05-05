class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        int result = 0, n = nums.size();
        for (int j = 0, i = 0, product = 1; j < n; ++j) {
            product *= nums[j];
            while (i <= j && product >= k) {
                product /= nums[i];
                ++i;
            }
            result += (j - i + 1);
        }
        return result;
    }
};