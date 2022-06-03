class Solution {
public:
    int consecutiveNumbersSum(int n) {
        int result = 0, k = 1;
        for (int k = 1; k * (k + 1) <= 2 * n; ++k) {
            if (k % 2 == 1) {
                if (n % k == 0) {
                    ++result;
                }
            } else {
                if (n % k != 0 && 2 * n % k == 0) {
                    ++result;
                }
            }
        }
        return result;
    }
};