class Solution {
public:
    int dominantIndex(vector<int>& nums) {
        int max_num_index = max_element(nums.begin(), nums.end()) - nums.begin();
        int max_num = nums[max_num_index];
        for (auto & num : nums) {
            if (num == max_num) {
                continue;
            }
            if (max_num < num * 2) {
                return -1;
            }
        }
        return max_num_index;
    }
};