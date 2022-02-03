class Solution {
public:
    int findMinFibonacciNumbers(int k) {
        vector<int> f;
        f.push_back(1);
        f.push_back(1);
        int a = 1, b = 1;
        while (a + b <= k) {
            int c = a + b;
            f.push_back(c);
            a = b;
            b = c;
        }
        int result = 0;
        for (int i = f.size() - 1; i >= 0 && k; --i) {
            if (k >= f[i]) {
                k -= f[i];
                ++result;
            }
        }
        return result;
    }
};