class Solution {
public:
    int largestSumAfterKNegations(vector<int>& nums, int k) {
        vector<int>::iterator it;
        while (k) {
            it = min_element(nums.begin(), nums.end());
            int minValue = *it, minPosition = it - nums.begin();
            if (minValue < 0) {
                nums[minPosition] = -nums[minPosition];
                --k;
            } else if (minValue == 0) {
                return accumulate(nums.begin(), nums.end(), 0);
            } else {
                if (k % 2 == 0) {
                    return accumulate(nums.begin(), nums.end(), 0);
                } else {
                    nums[minPosition] = -nums[minPosition];
                    return accumulate(nums.begin(), nums.end(), 0);
                }
            }
            
        }
        return accumulate(nums.begin(), nums.end(), 0);
    }
};