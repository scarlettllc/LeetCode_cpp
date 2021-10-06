class Solution {
public:
    int thirdMax(vector<int>& nums) {
        sort(nums.begin(), nums.end(), greater<int>());
        if (nums.size() < 3) {
            return nums[0];
        }
        int k = 1;
        for (int i = 1; i < nums.size(); ++i) {
            if (nums[i] != nums[i - 1]) {
                ++k;
            } else{
                continue;
            }
            if (k == 3) {
                return nums[i];
            }
        }
        return nums[0];
    }
};