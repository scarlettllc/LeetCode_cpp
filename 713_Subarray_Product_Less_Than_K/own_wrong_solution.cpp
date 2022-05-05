class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        int n = nums.size();
        vector<double> products(n + 1, 1);
        for (int i = 1; i <= n; ++i) {
            products[i] = products[i - 1] * nums[i - 1];
        }
        int result = 0;
        for (int i = 0; i < n; ++i) {
            for (int j = i; j < n; ++j) {
                if (products[j + 1] < k * products[i]) {
                    ++result;
                }
            }
        }
        return result;
    }
};