class Solution {
public:
    int minMoves2(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int result = 0, n = nums.size(), x = nums[n / 2];
        for (auto & num : nums) {
            result += abs(num - x);
        }
        return result;
    }
};