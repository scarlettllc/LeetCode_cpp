class Solution {
public:
    double quickMul(double x, long long int n) {
        double result = 1.0, x_contribute = x;
        while (n > 0) {
            if (n % 2 == 1) {
                result *= x_contribute;
            }
            x_contribute *= x_contribute;
            n /= 2;
        }
        return result;
    }
    double myPow(double x, int n) {
        return n >= 0 ? quickMul(x, n) : 1.0 / quickMul(x, -(long long int)n);
    }
};