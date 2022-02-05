class Solution {
private:
    int result;
    int n;
public:
    void dfs(int val, int idx, vector<int>& nums) {
        if (idx == n) {
            result += val;
            return;
        }
        dfs(val ^ nums[idx], idx + 1, nums);
        dfs(val, idx + 1, nums);
    }
    int subsetXORSum(vector<int>& nums) {
        result = 0;
        n = nums.size();
        dfs(0, 0, nums);
        return result;
    }
};