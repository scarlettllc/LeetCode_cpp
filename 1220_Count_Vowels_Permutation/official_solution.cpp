class Solution {
public:
    int countVowelPermutation(int n) {
        long long int mod = 1e9 + 7;
        vector<long long int> dp(5, 1);
        vector<long long int> ndp(5);
        for (int i = 1; i < n; ++i) {
            ndp[0] = (dp[1] + dp[2] + dp[4]) % mod;
            ndp[1] = (dp[0] + dp[2]) % mod;
            ndp[2] = (dp[1] + dp[3]) % mod;
            ndp[3] = dp[2] % mod;
            ndp[4] = (dp[2] + dp[3]) % mod;
            dp = ndp; 
        }
        return accumulate(dp.begin(), dp.end(), 0LL) % mod;
    }
};