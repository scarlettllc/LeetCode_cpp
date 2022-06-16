class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        if (k == 0) {
            unordered_map<int, int> cnt;
            for (auto & num : nums) {
                ++cnt[num];
            }
            int result = 0;
            for (auto & [num, freq] : cnt) {
                if (freq > 1) {
                    ++result;
                }
            }
            return result;
        }
        unordered_map<int, int> m; 
        for (int i = 0; i < nums.size(); ++i) {
            m[nums[i]] = i;
        }
        int result = 0;
        for (auto & [num, _] : m) {
            if (m.count(num + k)) {
                ++result;
            }
            if (m.count(num - k)) {
                ++result;
            }
        }
        return result / 2;
    }
};