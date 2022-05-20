class Solution {
public:
    int repeatedNTimes(vector<int>& nums) {
        for (int gap = 1; gap <= 3; ++gap) {
            for (int i = 0; i + gap < nums.size(); ++i) {
                if (nums[i] == nums[i + gap]) {
                    return nums[i];
                }
            }
        }
        return 0;
    }
};