class Solution {
public:
    int sumOfUnique(vector<int>& nums) {
        int result = 0;
        unordered_map<int, int> m;
        for (auto & num : nums) {
            if (m[num] == 0) {
                result += num;
                m[num] = 1;
            } else if (m[num] == 1) {
                result -= num;
                m[num] = 2;
            }
        }
        return result;
    }
};