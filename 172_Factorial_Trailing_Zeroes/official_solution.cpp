class Solution {
public:
    int trailingZeroes(int n) {
        int result = 0;
        for (int i = 5; i <= n; ++i) {
            for (int x = i; x % 5 == 0; x /= 5) {
                ++result;
            }
        }
        return result;
    }
};