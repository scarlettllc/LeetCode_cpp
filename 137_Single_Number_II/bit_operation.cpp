class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int result = 0;
        for (int i = 0; i < 32; ++i) {
            int total = 0;
            for (auto & num : nums) {
                total += ((num >> i) & 1);
            }
            if (total % 3) {
                result |= (1 << i);
            }
        }
        return result;
    }
};