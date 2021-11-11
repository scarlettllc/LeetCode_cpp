class Solution {
public:
    int kInversePairs(int n, int k) {
        int mod = 1000000007;
        vector<vector<int>> f(2, vector<int>(k + 1, 0));
        f[0][0] = 1;
        for (int i = 1; i <= n; ++i) {
            for (int j = 0; j <= k; ++j) {
                int cur = i & 1, pre = cur ^ 1;
                f[cur][j] = (j - 1 >= 0 ? f[cur][j - 1] : 0) - (j - i >= 0 ? f[pre][j - i] : 0) + f[pre][j];
                if (f[cur][j] >= mod) {
                    f[cur][j] -= mod;
                } else if (f[cur][j] < 0){
                    f[cur][j] += mod;
                }
            }
        }
        return f[n & 1][k];
    }
};