class Solution {
private:
    int m, n;
    vector<vector<int>> dirs{{-1, 0}, {1, 0}, {0, 1}, {0, -1}};
public:
    int getMaximumGold(vector<vector<int>>& grid) {
        int result = 0;
        m = grid.size(), n = grid[0].size();
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == 0) {
                    continue;
                }
                vector<vector<bool>> visited(m, vector<bool>(n, false));
                int temp_result = 0;
                dfs(i, j, grid, visited, result, temp_result);
            }
        }
        return result;
    }
    void dfs(int i, int j, vector<vector<int>>grid, vector<vector<bool>> visited, int & result, int temp_result) {
        if (i < 0 || i >= m || j < 0 || j >= n || visited[i][j] || grid[i][j] == 0) {
            result = max(result, temp_result);
            return;
        }
        visited[i][j] = true;
        temp_result += grid[i][j];
        result = max(result, temp_result);
        for (auto & dir : dirs) {
            int x = i + dir[0], y = j + dir[1];
            if (x < 0 || x >= m || y < 0 || y >= n || visited[x][y] || grid[x][y] == 0) {
                continue;
            }
            dfs(x, y, grid, visited, result, temp_result);
            result = max(result, temp_result);
            visited[x][y] = false;
            // temp_result -= grid[x][y];
        }
    }
};