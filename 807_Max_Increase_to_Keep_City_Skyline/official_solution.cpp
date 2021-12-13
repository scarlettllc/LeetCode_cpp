class Solution {
public:
    int maxIncreaseKeepingSkyline(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<int> max_rows(n, 0);
        vector<int> max_columns(n, 0);
        for (int i = 0; i < grid.size(); ++i) {
            for (int j = 0; j < grid[i].size(); ++j) {
                max_rows[i] = max(max_rows[i], grid[i][j]);
                max_columns[j] = max(max_columns[j], grid[i][j]);
            }
        }
        int result = 0;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j <n; ++j) {
                result += min(max_rows[i], max_columns[j]) - grid[i][j];
            }
        } 
        return result;
    }
};