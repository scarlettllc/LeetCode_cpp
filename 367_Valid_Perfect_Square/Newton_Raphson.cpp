class Solution {
public:
    bool isPerfectSquare(int num) {
        double x0 = num, x1;
        while (true) {
            x1 = (x0 + num / x0) / 2;
            if (abs(x1 - x0) < 1e-6) {
                break;
            }
            x0 = x1;
        }
        int x = int(x1);
        if (x * x == num) {
            return true;
        } else {
            return false;
        }
    }
};