class Solution {
public:
    int cherryPickup(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<vector<int>> f(n, vector<int>(n, INT_MIN));
        f[0][0] = grid[0][0];
        for (int k = 1; k < 2 * n - 1; ++k) {
            for (int x1 = min(k, n - 1); x1 >= max(k - n + 1, 0); --x1) {
                for (int x2 = min(k, n - 1); x2 >= x1; -- x2) {
                    int y1 = k - x1, y2 = k - x2;
                    if (grid[x1][y1] == -1 || grid[x2][y2] == -1) {
                        f[x1][x2] = INT_MIN;
                        continue;
                    }
                    int result = f[x1][x2];
                    if (x1) {
                        result = max(result, f[x1 - 1][x2]);
                    }
                    if (x2) {
                        result = max(result, f[x1][x2 - 1]);
                    }
                    if (x1 && x2) {
                        result = max(result, f[x1 - 1][x2 - 1]);
                    }
                    result += grid[x1][y1];
                    if (x2 != x1) {
                        result += grid[x2][y2];
                    }
                    f[x1][x2] = result;
                }
            }
        }
        return max(f.back().back(), 0);
    }
};