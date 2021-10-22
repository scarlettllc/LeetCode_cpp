class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int, int> m;
        for (int i = 0; i < n; ++i) {
            ++m[nums[i]];
        }
        unordered_map<int, int>::iterator it;
        for (it = m.begin(); it != m.end(); ++it) {
            if (it->second > n / 2) {
                return it->first;
            }
        }
        return 0;
    }
};