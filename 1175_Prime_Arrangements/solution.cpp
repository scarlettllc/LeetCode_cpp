class Solution {
private:
    const int MOD = 1e9+7;
public:
    int numPrimeArrangements(int n) {
        set<int> primes{2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 
        37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97};
        int count_prime = 0;
        for (int i = 1; i <= n; ++i) {
            if (primes.count(i)) {
                ++count_prime;
            }
        }
        return f(count_prime) * f(n - count_prime) % MOD;
    }
    long long int f(int m) {
        long long int result = 1;
        for (int i = 2; i <= m; ++i) {
            result *= i;
            result = result % MOD;
        }
        return result;
    }
};