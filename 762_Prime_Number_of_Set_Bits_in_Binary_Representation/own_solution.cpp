class Solution {
public:
    int countPrimeSetBits(int left, int right) {
        int result = 0;
        for (int i = left; i <= right; ++i) {
            if (isPrime(num_of_set_bits(i))) {
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
    int num_of_set_bits(int num) {
        int result = 0;
        while (num) {
            result += (num % 2);
            num /= 2;
        }
        return result;
    }
};