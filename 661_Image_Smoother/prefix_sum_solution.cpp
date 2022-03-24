class Solution {
public:
    vector<vector<int>> imageSmoother(vector<vector<int>>& img) {
        int m = img.size(), n = img[0].size();
        vector<vector<int>> prefix_sum(m + 1, vector<int>(n + 1, 0));
        for (int i = 1; i <= m; ++i) {
            for (int j = 1; j <= n; ++j) {
                prefix_sum[i][j] = img[i - 1][j - 1] + prefix_sum[i - 1][j] + prefix_sum[i][j - 1] - prefix_sum[i - 1][j - 1];
            }
        }
        vector<vector<int>> result(m, vector<int>(n, 0));
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                int row1 = max(0, i - 1), row2 = min(m - 1, i + 1);
                int col1 = max(0, j - 1), col2 = min(n - 1, j + 1);
                int num = (row2 - row1 + 1) * (col2 - col1 + 1);
                int sum = prefix_sum[row2 + 1][col2 + 1] - prefix_sum[row1][col2 + 1] - prefix_sum[row2 + 1][col1] + prefix_sum[row1][col1];
                result[i][j] = sum / num; 
            }
        }
        return result;
    }
};