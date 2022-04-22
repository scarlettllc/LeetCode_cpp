class Solution {
public:
    int maxRotateFunction(vector<int>& nums) {
        int n = nums.size(), result = INT_MIN;
        for (int k = 0; k < n; ++k) {
            result = max(result, get_F(nums, n, k));
        }
        return result;
    }
    int get_F(vector<int>& nums, int n, int k) {
        int result = 0;
        for (int i = k; i < n; ++i) {
            result += i * nums[i - k];
        }
        for (int i = n - k; i < n; ++i) {
            result += (i - n + k) * nums[i];
        }
        return result;
    }
};