class Solution {
private:
    vector<vector<int>> heights;
    int m, n;
    vector<vector<int>> dirs{{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
public:
    void dfs(int i, int j, vector<vector<bool>>& ocean) {
        if (ocean[i][j]) {
            return;
        }
        ocean[i][j] = true;
        for (auto & dir : dirs) {
            int x = i + dir[0], y = j + dir[1];
            if (x >= 0 && x < m && y >= 0 && y < n && heights[x][y] >= heights[i][j]) {
                dfs(x, y, ocean);
            }
        }
    }
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        this->heights = heights;
        m = heights.size(), n = heights[0].size();
        vector<vector<bool>> pacific(m, vector<bool>(n, false));
        vector<vector<bool>> atlantic(m, vector<bool>(n, false));
        for (int i = 0; i < m; ++i) {
            dfs(i, 0, pacific);
        } 
        for (int j = 1; j < n; ++j) {
            dfs(0, j, pacific);
        }
        for (int j = 0; j < n; ++j) {
            dfs(m - 1, j, atlantic);
        }
        for (int i = 0; i < m - 1; ++i) {
            dfs(i, n - 1, atlantic);
        }
        vector<vector<int>> result;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (pacific[i][j] && atlantic[i][j]) {
                    result.push_back({i, j});
                }
            }
        }
        return result;
    }
};