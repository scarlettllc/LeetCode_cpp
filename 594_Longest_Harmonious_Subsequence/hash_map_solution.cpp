class Solution {
public:
    int findLHS(vector<int>& nums) {
        unordered_map<int, int> cnt;
        for (auto & num : nums) {
            ++cnt[num];
        }
        int result = 0;
        for (auto & [key, val] : cnt) {
            if (cnt.count(key + 1)) {
                result = max(result, val + cnt[key + 1]);
            }
        }
        return result;
    }
};