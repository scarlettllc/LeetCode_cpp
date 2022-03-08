class Solution {
public:
    vector<int> platesBetweenCandles(string s, vector<vector<int>>& queries) {
        int n = s.size();
        int m = queries.size();
        vector<int> dp(n, 0);
        int left = n, right = -1;
        for (int i = 0; i < n; ++i) {
            if (s[i] == '|') {
                left = i;
                break;
            }
        }
        for (int i = n - 1; i >= 0; --i) {
            if (s[i] == '|') {
                right = i;
                break;
            }
        }
        if (left == n || right == -1) {
            return dp;
        }
        for (int i = left + 1; i <= right; ++i) {
            if (s[i] == '*') {
                dp[i] = dp[i - 1] + 1;
            } else {
                dp[i] = dp[i - 1];
            }
        }
        vector<int> result(m, 0);
        for (int i = 0; i < m; ++i) {
            int query_left = queries[i][0], query_right = queries[i][1];
            int valid_left = query_right, valid_right = query_left;
            for (int j = query_left; j <= query_right; ++j) {
                if (s[j] == '|') {
                    valid_left = j;
                    break;
                }
            }
            for (int j = query_right; j >= query_left; --j) {
                if (s[j] == '|') {
                    valid_right = j;
                    break;
                }
            }
            if (valid_left == query_right || valid_right == query_left) {
                result[i] = 0;
            } else {
                result[i] = dp[valid_right] - dp[valid_left];
            }
        }
        return result;
     }
};