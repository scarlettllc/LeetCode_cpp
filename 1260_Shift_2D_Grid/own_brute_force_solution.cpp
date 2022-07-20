class Solution {
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
        int m = grid.size(), n = grid[0].size();
        for (int cnt = 0; cnt < k; ++cnt) {
            vector<int> temp;
            for (int i = 0; i < m; ++i) {
                temp.push_back(grid[i][n - 1]);
            }
            for (int i = 0; i < m; ++i) {
                for (int j = n - 1; j >= 1; --j) {
                    grid[i][j] = grid[i][j - 1];
                }
            }
            for (int i = 1; i < m; ++i) {
                grid[i][0] = temp[i - 1];
            }
            grid[0][0] = temp[m - 1];
        }
        return grid;
    }
};