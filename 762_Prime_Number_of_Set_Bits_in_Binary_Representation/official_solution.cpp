class Solution {
public:
    int countPrimeSetBits(int left, int right) {
        int result = 0;
        for (int i = left; i <= right; ++i) {
            if (isPrime(__builtin_popcount(i))) {
                ++result;
            }
        }
        return result;
    }
    bool isPrime(int num) {
        if (num == 1) {
            return false;
        }
        for (int i = 2; i <= sqrt(num); ++i) {
            if (num % i == 0) {
                return false;
            }
        }
        return true;
    }
};