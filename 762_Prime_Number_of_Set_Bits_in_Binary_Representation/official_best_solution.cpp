class Solution {
public:
    int countPrimeSetBits(int left, int right) {
        int result = 0;
        for (int i = left; i <= right; ++i) {
            if ((1 << __builtin_popcount(i)) & 665772) {
                ++result;
            }
        }
        return result;
    }
};