class Solution {
public:
    int nthMagicalNumber(int n, int a, int b) {
        int mod = 1e9 + 7;
        int l = a / gcd(a, b) * b;
        int m = l / a + l / b - 1;
        int q = n / m, r = n % m;
        long result = (long)l * q % mod;
        if (r == 0) {
            return (int)result;
        }
        int heads[2] = {a, b};
        for (int i = 1; i < r; ++i) {
            if (heads[0] <= heads[1]) {
                heads[0] += a;
            } else {
                heads[1] += b;
            }
        }
        result += min(heads[0], heads[1]);
        return (int)(result % mod);
    }
    int gcd(int x, int y) {
        if (x == 0) {
            return y;
        }
        return gcd(y % x, x);
    }
};
