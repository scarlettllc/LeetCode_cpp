class Solution {
public:
    bool isPerfectSquare(int num) {
        if(pow(int(sqrt(num)), 2) == num) {
            return true;
        }
        return false;
    }
};