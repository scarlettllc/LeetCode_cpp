class Solution {
public:
    int sumOfUnique(vector<int>& nums) {
        int result = 0;
        unordered_map<int, int> m;
        for (auto & num : nums) {
            ++m[num];
        }
        for (auto & item : m) {
            if (item.second == 1) {
                result += item.first;
            }
        }
        return result;
    }
};