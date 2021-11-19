class Solution {
private:
    unordered_map<int, int> memo;
public:
    int integerReplacement(int n) {
        if (n == 1) {
            return 0;
        }
        if (memo.count(n)) {
            return memo[n];
        }
        if (n % 2 == 0) {
            return memo[n] = (1 + integerReplacement(n / 2));
        } else {
            return memo[n] = (2 + min(integerReplacement(n / 2 + 1), integerReplacement(n / 2)));
        }
    }
};