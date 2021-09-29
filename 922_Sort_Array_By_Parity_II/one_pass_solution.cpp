class Solution {
public:
    vector<int> sortArrayByParityII(vector<int>& nums) {
        vector<int> even, odd;
        int n = nums.size();
        for (int i = 0; i < n; ++i) {
            if (nums[i] % 2 == 0) {
                even.emplace_back(nums[i]);
            } else{
                odd.emplace_back(nums[i]);
            }
        }
        for (int i = 0; i < n / 2; ++i) {
            nums[2 * i] = even[i];
            nums[2 * i + 1] = odd[i];
        }
        return nums;
    }
};