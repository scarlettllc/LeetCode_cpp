class Solution {
public:
    bool hasAlternatingBits(int n) {
        int temp, last = -1;
        while (n) {
            temp = n % 2;
            if (temp == last) {
                return false;
            }
            n /= 2;
            last = temp;
        }
        return true;
    }
};