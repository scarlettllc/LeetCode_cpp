class Solution {
public:
    long _count(long n, long a, long b, long c, long l_ab, long l_ac, long l_bc, long l_abc) {
        return n / a + n / b + n / c - n / l_ab - n / l_ac - n / l_bc + n / l_abc;
    }
    int nthUglyNumber(int n, int a, int b, int c) {
        long gcd_ab = gcd(a, b), gcd_ac = gcd(a, c), gcd_bc = gcd(b, c);
        long l_ab = a / gcd_ab * b;
        long l_ac = a / gcd_ac * c;
        long l_bc = (long)b / gcd_bc * c;
        long l_abc = l_ab / gcd(l_ab, l_ac) * l_ac;
        long m = _count(l_abc, a, b, c, l_ab, l_ac, l_bc, l_abc);
        long q = n / m, r = n % m;
        long result = l_abc * q;
        if (r == 0) {
            return (int)result;
        }
        long low = min(a, min(b, c)), high = l_abc;
        while (low < high) {
            long mid = low + ((high - low) >> 1);
            if (_count(mid, a, b, c, l_ab, l_ac, l_bc, l_abc) < r) {
                low = mid + 1;
            } else {
                high = mid;
            }
        }
        return result + low;
    }
    long gcd(long x, long y) {
        if (x == 0) {
            return y;
        }
        return gcd(y % x, x);
    }
};
