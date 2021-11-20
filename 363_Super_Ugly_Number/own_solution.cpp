class Solution {
public:
    int nthSuperUglyNumber(int n, vector<int>& primes) {
        vector<long> dp(n + 1);
        int m = primes.size();
        vector<int> p(m, 1);
        vector<long> nums(m);
        for (int i = 0; i < m; ++i) {
            nums[i] = primes[i];
        }
        dp[1] = 1;
        for (int i = 2; i <= n; ++i) {
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