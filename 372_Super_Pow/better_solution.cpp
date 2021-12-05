class Solution {
private:
    const int num = 1337;
public:
    int superPow(int a, vector<int>& b) {
        int result = 1;
        for (int i = b.size() - 1; i >= 0; --i) {
            result = result * quick_pow(a, b[i]) % num;
            a = quick_pow(a, 10) % num;
        }
        return result;
    }
    int quick_pow(int a, int b) {
        if (b == 0) {
            return 1;
        }
        if (a == 1) {
            return 1;
        }
        a = a % num;
        int result = 1;
        while (b) {
            if (b & 1) {
                result = result * a % num;
            }
            a = a % num * a % num;
            b >>= 1;
        }
        return result % num;
    }
};