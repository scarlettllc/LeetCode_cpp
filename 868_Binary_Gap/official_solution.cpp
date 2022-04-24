class Solution {
public:
    int binaryGap(int n) {
        int last = -1, result = 0;
        for (int i = 0; n; ++i) {
            if (n & 1) {
                if (last != -1) {
                    result = max(result, i - last);
                }
                last = i;
            }
            n >>= 1;
        }
        return result;
    }
};