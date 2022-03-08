class Solution {
public:
    vector<int> platesBetweenCandles(string s, vector<vector<int>>& queries) {
        int n = s.size();
        int m = queries.size();
        vector<int> dp(n, 0);
        int sum = 0;
        for (int i = 0; i < n; ++i) {
            if (s[i] == '*') {
                ++sum;
            } 
            dp[i] = sum;
        }
        vector<int> left(n);
        for (int i = 0, l = -1; i < n; ++i) {
            if (s[i] == '|') {
                l = i;
            }
            left[i] = l;
        }
        vector<int> right(n);
        for (int i = n - 1, r = -1; i >= 0; --i) {
            if (s[i] == '|') {
                r = i;
            }
            right[i] = r;
        }
        vector<int> result(m, 0);
        for (int i = 0; i < m; ++i) {
            int x = right[queries[i][0]], y = left[queries[i][1]];
            result[i] = (x == -1 || y == -1 || x >= y)? 0 : dp[y] - dp[x];
        }
        return result;
     }
};