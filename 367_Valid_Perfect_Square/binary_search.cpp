class Solution {
public:
    bool isPerfectSquare(int num) {
        int left = 1, right = num;
        long long int mid;
        while (left <= right) {
            mid = left + (right - left) / 2;
            if (mid * mid > num) {
                right = mid - 1;
            } else if (mid * mid < num){
                left = mid + 1;
            } else {
                return true;
            }
        }
        return false;
    }
};