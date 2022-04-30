class Solution {
public:
    int smallestRangeI(vector<int>& nums, int k) {
        int max_value = *max_element(nums.begin(), nums.end());
        int min_value = *min_element(nums.begin(), nums.end());
        return max_value - min_value <= 2 * k? 0 : max_value - min_value - 2 * k;
    }
};