class Solution {
public:
    int lastRemaining(int n) {
        int k = 0, step = 1, cnt = n, a1 = 1, an = n;
        while (cnt > 1) {
            if (k % 2 == 0) {
                a1 += step;
                an = (cnt % 2 == 0? an : an - step);
            } else {
                a1 = (cnt % 2 == 0? a1 : a1 + step);
                an = an - step;
            }
            ++k;
            cnt = cnt >> 1;
            step = step << 1;
        }
        return a1;
    }
};