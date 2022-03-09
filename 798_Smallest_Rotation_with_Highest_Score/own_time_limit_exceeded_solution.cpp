class Solution {
public:
    int bestRotation(vector<int>& nums) {
        int result = 0, K = -1;
        int n = nums.size();
        for (int k = 0; k < n; ++k) {
            int temp_result = 0;
            for (int j = k; j < n; ++j) {
                if (nums[j] <= j - k) {
                    ++temp_result;
                }
            }
            for (int j = 0; j < k; ++j) {
                if (nums[j] <= j + n - k) {
                    ++temp_result;
                }
            }
            if (temp_result > result || (temp_result == result && k < K)) {
                result = temp_result;
                K = k;
            }
        }
        return K;
    }
};