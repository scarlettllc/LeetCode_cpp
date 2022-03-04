class Solution {
public:
    long long subArrayRanges(vector<int>& nums) {
        long long result = 0, n = nums.size();
        for (int i = 0; i < n; ++i) {
            int temp_min = nums[i], temp_max = nums[i];
            for (int j = i + 1; j < n; ++j) {
                temp_min = min(temp_min, nums[j]);
                temp_max = max(temp_max, nums[j]);
                result += (temp_max - temp_min);
            }
        }
        return result;
    }
};