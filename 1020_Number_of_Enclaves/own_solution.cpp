class Solution {
private:
    vector<vector<int>> dirs{{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
public:
    int numEnclaves(vector<vector<int>>& grid) {
        int total = 0, m = grid.size(), n = grid[0].size();
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j]) {
                    ++total;
                }
            }
        }
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if ((i == 0 || i == m - 1 || j == 0 || j == n - 1) && grid[i][j] == 1) {
                    dfs(i, j, m, n, grid);
                }
            }
        }
        int available = 0;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == -1) {
                    ++available;
                }
            }
        }
        return total - available;
    }
    void dfs(int i, int j, int m, int n, vector<vector<int>>& grid) {
        grid[i][j] = -1;
        for (auto & dir : dirs) {
            int x = i + dir[0], y = j + dir[1];
            if (x >= 0 && x < m && y >= 0 && y < n && grid[x][y] == 1) {
                dfs(x, y, m, n, grid);
            }
        }
    }
};