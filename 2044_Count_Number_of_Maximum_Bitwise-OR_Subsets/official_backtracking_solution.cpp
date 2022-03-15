class Solution {
public: 
    int max_result;
    int count;
    vector<int> _nums;
    int countMaxOrSubsets(vector<int>& nums) {
        max_result = 0;
        count = 0;
        _nums = nums;
        dfs(0, 0);
        return count;
    }
    void dfs(int pos, int temp_or_result) {
        if (pos == _nums.size()) {
            if (temp_or_result == max_result) {
                ++count;
            } else if (temp_or_result > max_result) {
                max_result = temp_or_result;
                count = 1;
            }
            return;
        }
        dfs(pos + 1, temp_or_result | _nums[pos]);
        dfs(pos + 1, temp_or_result);
    }
};