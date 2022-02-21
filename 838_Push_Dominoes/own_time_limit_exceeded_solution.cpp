class Solution {
public:
    string pushDominoes(string dominoes) {
        int n = dominoes.size();
        vector<vector<char>> dp(n, vector<char>(n, '.'));
        for (int j = 0; j < n; ++j) {
            dp[0][j] = dominoes[j];
        }
        bool flag = true;
        int i;
        for (i = 1; i < n && flag; ++i) {
            flag = true;
            for (int j = 0; j < n; ++j) {
                if (dp[i - 1][j] != '.') {
                    dp[i][j] = dp[i - 1][j];
                    continue;
                }
                bool flag1 = (j + 1 < n && dp[i - 1][j + 1] == 'L');
                bool flag2 = (j > 0 && dp[i - 1][j - 1] == 'R');
                if (flag1 && flag2) {
                    dp[i][j] = '.';
                } else if (flag1 && !flag2) {
                    dp[i][j] = 'L';
                } else if (!flag1 && flag2) {
                    dp[i][j] = 'R';
                } else {
                    dp[i][j] = '.';
                }
            }
            if (dp[i] == dp[i - 1]) {
                flag = false;
            }
        }
        string result = "";
        for (int j = 0; j < n; ++j) {
            result += dp[i - 1][j];
        }
        return result;
    }
};