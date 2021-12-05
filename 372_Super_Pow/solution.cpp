class Solution {
private:
    const int num = 1337;
public:
    int superPow(int a, vector<int>& b) {
        return dfs(a, b, b.size() - 1);
    }
    int dfs(int a, vector<int> b, int u) {
        if (u == 0) {
            return qpow(a, b[u]) % num;
        }
        return qpow(dfs(a, b, u - 1), 10) % num * qpow(a, b[u]) % num;
    }
    int qpow(int a, int b) {
        if (b == 0) {
            return 1;
        };
        a = a % num;
        int result = 1;
        while (b) {
            if (b & 1) {
                result = result * (a % num);
            }
            a = a * a % num;
            b >>= 1;
        }
        return result % num;
    }
};