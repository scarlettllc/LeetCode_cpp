class Solution {
public:
    vector<vector<int>> colorBorder(vector<vector<int>>& grid, int row, int col, int color) {
        vector<vector<int>> result = grid;
        int original = grid[row][col];
        dfs(result, row, col, original);
        for (int i = 0; i < result.size(); ++i) {
            for (int j = 0; j < result[0].size(); ++j) {
                if (result[i][j] == 0) {
                    result[i][j] = color;
                } else if (result[i][j] == -1) {
                    result[i][j] = original;
                }
            }
        }
        return result;
    }
    void dfs(vector<vector<int>>& result, int row, int col, int& original) {
        if (row < 0 || row >= result.size() || col < 0 || col >= result[0].size()) {
            return;
        }
        if (result[row][col] == 0) {
            return;
        }
        if (result[row][col] == original) {
            if (row == 0 || row == result.size() - 1 || col == 0 || col == result[0].size() - 1 || \
            (col < result[0].size() - 1 && result[row][col + 1] != original && result[row][col + 1] != 0 && result[row][col + 1] != -1) || \
            (col > 0 && result[row][col - 1] != original && result[row][col - 1] != 0 && result[row][col - 1] != -1) || \
            (row < result.size() - 1 && result[row + 1][col] != original && result[row + 1][col] != 0 && result[row + 1][col] != -1) || \
            (row > 0 && result[row - 1][col] != original && result[row - 1][col] != 0 && result[row - 1][col] != -1)) {
                result[row][col] = 0;
            }
            else {
                result[row][col] = -1;
            }
            dfs(result, row, col + 1, original);
            dfs(result, row, col - 1, original);
            dfs(result, row + 1, col, original);
            dfs(result, row - 1, col, original);
        }
    }
};