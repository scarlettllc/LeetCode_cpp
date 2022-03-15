class Solution {
public:
    vector<int> _nums;
    vector<int> temp;
    map<int, int> result;
    void dfs(int cur, int n, int k) {
        if (temp.size() + n - cur + 1 < k) {
            return;
        }
        if (temp.size() == k) {
            ++result[count_or_result(temp)];
            return;
        }
        temp.push_back(_nums[cur - 1]);
        dfs(cur + 1, n, k);
        temp.pop_back();
        dfs(cur + 1, n, k);
    }
    int count_or_result(vector<int>& temp) {
        int result = temp[0];
        for (int i = 1; i < temp.size(); ++i) {
            result |= temp[i];
        }
        return result;
    }
    int countMaxOrSubsets(vector<int>& nums) {
        _nums = nums;
        int n = nums.size();
        for (int i = 1; i <= n; ++i) {
            dfs(1, n, i);
        }
        return result.rbegin()->second;
    }
};