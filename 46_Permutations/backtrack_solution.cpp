class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> result;
        vector<int> temp(nums);
        int idx = 0;
        backtrack(result, nums, temp, idx);
        return result;
    }
    void backtrack(vector<vector<int>>& result, vector<int>& nums, vector<int>& temp, int idx) {
        if (idx == nums.size()) {
            result.push_back(temp);
        }
        for (int j = idx; j < nums.size(); ++j) {
            swap(temp[idx], temp[j]);
            backtrack(result, nums, temp, idx + 1);
            swap(temp[idx], temp[j]);
        }
    }
};