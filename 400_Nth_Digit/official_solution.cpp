class Solution {
public:
    int findNthDigit(int n) {
        int d = 1, count = 9;
        while (n > (long)d * count) {
            n -= d * count;
            ++d;
            count *= 10;
        }
        int index = n - 1;
        int num = int(pow(10, d - 1)) + index / d;
        int digit_index = index % d;
        return (num / (int)pow(10, d - digit_index - 1)) % 10; 
    }
};