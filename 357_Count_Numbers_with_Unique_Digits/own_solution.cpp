class Solution {
public:
    int countNumbersWithUniqueDigits(int n) {
        if (n == 0) {
            return 1;
        }
        if (n == 1) {
            return 10;
        }
        int sum = 10, temp_sum = 9, temp = 9;
        for (int i = 0; i < n - 1; ++i) {
            temp_sum *= temp;
            sum += temp_sum;
            --temp;
        }
        return sum;
    }
};