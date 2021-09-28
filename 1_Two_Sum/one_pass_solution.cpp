class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> value_index;
        int n = nums.size();
        for (int i = 0; i < n; ++i) {
            if (value_index.find(target - nums[i]) != value_index.end()) {
                return {value_index[target - nums[i]], i};
            } else {
                value_index.insert(make_pair(nums[i], i));
            }
        }
        return {0, 0};
    }
};

//时间复杂度：O(N)
//空间复杂度：O(N)