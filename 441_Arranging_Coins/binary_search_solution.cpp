class Solution {
public:
    int arrangeCoins(int n) {
        int left = 1, right = n;
        while (left < right) {
            int mid = (right - left + 1) / 2 + left;
            if ((long int)mid * (mid + 1) <= 2 * (long int)n) {
                left = mid;
            } else {
                right = mid - 1;
            }
        }
        return left;
    }
};