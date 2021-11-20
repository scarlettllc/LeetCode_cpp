class Solution {
public:
    int nthSuperUglyNumber(int n, vector<int>& primes) {
        vector<long> dp(n + 1);
        int m = primes.size();
        vector<int> p(m, 0);
        vector<long> nums(m, 1);
        for (int i = 1; i <= n; ++i) {
            dp[i] = nums[0];
            for (int j = 1; j < m; ++j) {
                if (nums[j] < dp[i]) {
                    dp[i] = nums[j];
                }
            }
            for (int j = 0; j < m; ++j) {
                if (dp[i] == nums[j]) {
                    ++p[j];
                    nums[j] = dp[p[j]] * primes[j];
                }
            }
        }
        return dp[n];
    }
};