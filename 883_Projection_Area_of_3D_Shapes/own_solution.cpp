class Solution {
public:
    int projectionArea(vector<vector<int>>& grid) {
        int result = 0, m = grid.size(), n = grid[0].size();
        for (int i = 0; i < m; ++i) {
            result += *max_element(grid[i].begin(), grid[i].end());
        }
        for (int j = 0; j < n; ++j) {
            int max_col = 0;
            for (int i = 0; i < m; ++i) {
                if (grid[i][j] != 0) {
                    ++result;
                }
                max_col = max(grid[i][j], max_col);
            }
            result += max_col;
        }
        return result;
    }
};