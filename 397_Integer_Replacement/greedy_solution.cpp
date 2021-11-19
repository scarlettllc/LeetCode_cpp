class Solution {
public:
    int integerReplacement(int n) {
        int result = 0;
        while (n != 1) {
            if (n % 2 == 0) {
                ++result;
                n /= 2;
            } else if (n % 4 == 1) {
                result += 2;
                n /= 2;
            } else {
                if (n == 3){ 
                    result += 2;
                    n = 1;
                } else {
                    result += 2;
                    n = n / 2 + 1;
                }
            }
        }
        return result;
    }
};