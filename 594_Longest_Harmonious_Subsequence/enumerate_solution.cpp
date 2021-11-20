class Solution {
public:
    int findLHS(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int result = 0, begin = 0;
        for (int end = 0; end < nums.size(); ++end) {
            while (nums[end] - nums[begin] > 1) {
                ++begin;
            }
            if (nums[end] - nums[begin] == 1) {
                result = max(result, end - begin + 1);
            }
        }
        return result;
    }
};