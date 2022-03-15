class Solution {
public:
    int countMaxOrSubsets(vector<int>& nums) {
        int max_result = 0, count = 0;
        int n = nums.size(), statenumber = (1 << n);
        for (int i = 0; i < statenumber; ++i) {
            int temp_result = 0;
            for (int j = 0; j < n; ++j) {
                if ((i >> j) & 1 == 1) {
                    temp_result |= nums[j];
                }
            }
            if (temp_result > max_result) {
                max_result = temp_result;
                count = 1;
            } else if (temp_result == max_result) {
                ++count;
            }
        }
        return count;
    }
};