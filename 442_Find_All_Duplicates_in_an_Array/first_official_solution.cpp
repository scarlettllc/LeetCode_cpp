class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        int n = nums.size();
        for (int i = 0; i < n; ++i) {
            while (nums[i] != nums[nums[i] - 1]) {
                swap(nums[i], nums[nums[i] - 1]);
            }
        }
        vector<int> result;
        for (int i = 0; i < n; ++i) {
            if (nums[i] - 1 != i) {
                result.push_back(nums[i]);
            }
        }
        return result;
    }
};