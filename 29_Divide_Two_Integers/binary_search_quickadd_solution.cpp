class Solution {
public:
    bool quickAdd(int y, int z, int x) {
        int result = 0, add = y;
        while (z) {
            if (z & 1) {
                if (result < x - add) {
                    return false;
                }
                result += add;
            }
            if (z != 1) {
                if (add < x - add) {
                    return false;
                }
                add += add;
            }            
            z >>= 1;
        }
        return true;
    }
    int divide(int dividend, int divisor) {
        if (dividend == INT_MIN) {
            if (divisor == -1) {
                return INT_MAX;
            }
            if (divisor == 1) {
                return INT_MIN;
            }
        }
        if (divisor == INT_MIN) {
            return dividend == INT_MIN ? 1 : 0;
        }
        if (dividend == 0) {
            return 0;
        }
        bool flag = true;
        if (dividend > 0) {
            dividend = -dividend;
            flag = !flag;
        }
        if (divisor > 0) {
            divisor = -divisor;
            flag = !flag;
        }
        int left = 1, right = INT_MAX, mid, result = 0;
        while (left <= right) {
            mid = left + ((right - left) >> 1);
            if (quickAdd(divisor, mid, dividend)) {
                result = mid;
                if (mid == INT_MAX) {
                    break;
                }
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        return flag? result : (-result);
     }
};