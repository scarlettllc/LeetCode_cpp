class Solution {
public:
    int nthUglyNumber(int n, int a, int b, int c) {
        long gcd_ab = gcd(a, b), gcd_ac = gcd(a, c), gcd_bc = gcd(b, c);
        long l_ab = a / gcd_ab * b;
        long l_ac = a / gcd_ac * c;
        long l_bc = (long)b / gcd_bc * c;
        long l = l_ab / gcd(l_ab, l_ac) * l_ac;
        long m = l / a + l / b + l / c - l / l_ab - l / l_ac - l / l_bc + 1;
        long q = n / m, r = n % m;
        long result = l * q;
        if (r == 0) {
            return (int)result;
        }
        long heads[3] = {a, b, c};
        for (int i = 1; i < r; ++i) {
            int temp = min(heads[0], min(heads[1], heads[2]));
            if (heads[0] == temp) {
                heads[0] += a;
            }
            if (heads[1] == temp) {
                heads[1] += b;
            }
            if (heads[2] == temp) {
                heads[2] += c;
            }
        }
        result += min(heads[0], min(heads[1], heads[2]));
        return result;
    }
    long gcd(long x, long y) {
        if (x == 0) {
            return y;
        }
        return gcd(y % x, x);
    }
};
