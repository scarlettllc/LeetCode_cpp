class Solution {
private:
    map<int, set<int>> m;
public:
    int arrayNesting(vector<int>& nums) {
        int n = nums.size(), result = 0;
        for (int i = 0; i < n; ++i) {
            if (!m.count(i)) {
                helper(nums, i);
            }
            int temp = m[i].size();
            result = max(result, temp);
        }
        return result;
    }
    void helper(vector<int>& nums, int i) {
        if (m.count(i)) {
            return;
        }
        while (true) {
            if (!m[i].count(nums[i])) {
                m[i].insert(nums[i]);
                int i_0 = i;
                i = nums[i];
                helper(nums, i);
                m[i_0].insert(m[i].begin(), m[i].end());
                return;
            } else {
                break;
            }
        }
    }
};