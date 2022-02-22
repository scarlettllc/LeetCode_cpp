class Solution {
public:
    vector<unordered_map<int, int>> nums_primes;
    vector<int> temp;
    vector<vector<int>> combinations;
    vector<int> _nums;
    void dfs(int cur, int n, int k) {
        if (temp.size() + n - cur + 1 < k) {
            return;
        }
        if (temp.size() == k) {
            unordered_map<int, int> m;
            unordered_map<int, int>::iterator it;
            for (int i = 0; i < k; ++i) {
                unordered_map<int, int> temp_m = nums_primes[temp[i]];
                for (it = temp_m.begin(); it != temp_m.end(); ++it) {
                    m[it->first] += it->second;
                }
            }
            bool flag = true;
            for (it = m.begin(); it != m.end(); ++it) {
                if (it->second > 1) {
                    flag = false;
                    break;
                }
            }
            if (flag) {
                combinations.push_back(temp);
            }
            return;
        }
        temp.push_back(cur - 1);
        dfs(cur + 1, n, k);
        temp.pop_back();
        dfs(cur + 1, n, k);
    }
    int numberOfGoodSubsets(vector<int>& nums) {
        vector<int> temp_nums;
        int count = 0;
        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] == 1) {
                ++count;
            } else {
                temp_nums.push_back(nums[i]);
            }
        }
        nums = temp_nums;
        _nums = nums;
        bool flag = true;
        for (int i = 0; i < nums.size(); ++i) {
            nums_primes.push_back(prime_decomposition(nums[i]));
        }
        vector<unordered_map<int, int>> _nums_primes;
        unordered_map<int, int>::iterator it;
        for (int i = 0; i < nums.size(); ++i) {
            bool flag1 = true;
            unordered_map<int, int> temp_m = nums_primes[i];
            for (it = temp_m.begin(); it != temp_m.end(); ++it) {
                if (it->second > 1) {
                    flag1 = false;
                    break;
                }
            }
            if (flag1) {
                _nums_primes.push_back(temp_m);
            }
        }
        nums_primes = _nums_primes;
        int n = nums_primes.size();
        for (int i = 2; i <= n; ++i) {
            dfs(1, n, i);
        }
        return (combinations.size() + nums_primes.size()) * pow(2, count);
    }
    unordered_map<int, int> prime_decomposition(int n) {
        unordered_map<int, int> result;
        if (n == 1) {
            return result;
        }
        int end = sqrt(n) + 1;
        for (int i = 2; i <= end; ++i) {
            while (n % i == 0) {
                ++result[i];
                n = n / i;
            } 
            if (n == 1) {
                break;
            }
        }
        if (n != 1) {
            ++result[n];
        }
        return result;
    }    
};