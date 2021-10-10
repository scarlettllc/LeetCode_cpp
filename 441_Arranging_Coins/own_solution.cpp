class Solution {
public:
    int arrangeCoins(int n) {
        int result = 0;
        int i = 0;
        while (n > 0) {
            ++i;
            n -= i;
            ++result;
        }
        if (n < 0) {
            --result;
        }
        return result;
    }
};