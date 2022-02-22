class Solution {
public:
    int numberOfGoodSubsets(vector<int>& nums) {
        vector<int> primes{2, 3, 5, 7, 11, 13, 17, 19, 23, 29};
        int mod = 1000000007;
        int max_num = 30;
        vector<int> freq(max_num + 1, 0);
        for (auto & num : nums) {
            ++freq[num];
        }
        vector<int> f(1 << primes.size());
        f[0] = 1;
        for (int _ = 0; _ < freq[1]; ++_) {
            f[0] = f[0] * 2 % mod;
        }
        for (int i = 2; i <= 30; ++i) {
            if (!freq[i]) {
                continue;
            }
            bool check = true;
            int subset = 0;
            for (int j = 0; j < primes.size(); ++j) {
                int prime = primes[j];
                if (i % (prime * prime) == 0) {
                    check = false;
                    break;
                }
                if (i % prime == 0) {
                    subset |= (1 << j);
                }
            }
            if (!check) {
                continue;
            }
            for (int mask = (1 << primes.size()) - 1; mask > 0; --mask) {
                if ((mask & subset) == subset) {
                    f[mask] = (f[mask] + (long long int)f[mask ^ subset] * freq[i]) % mod;
                }
            }
        }
        int result = 0;
        for (int mask = 1, max_mask = (1 << primes.size()); mask < max_mask; ++mask) {
            result = (result + f[mask]) % mod;
        }
        return result;
    }
};