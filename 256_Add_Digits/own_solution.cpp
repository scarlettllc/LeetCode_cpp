class Solution {
public:
    int addDigits(int num) {
        while (num / 10) {
            int sum = 0, temp_num = num;
            while (temp_num) {
                sum += temp_num % 10;
                temp_num /= 10;
            }
            num = sum;
        }
        return num;
    }
};