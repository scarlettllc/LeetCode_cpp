int dirs[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
class Solution {
public:
    vector<vector<int>> highestPeak(vector<vector<int>>& isWater) {
        int m = isWater.size(), n = isWater[0].size();
        vector<vector<int>> result(m, vector<int>(n, -1));
        queue<pair<int, int>> q;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (isWater[i][j]) {
                    result[i][j] = 0;
                    q.emplace(i, j);
                }
            }
        }
        int i, j;
        while (!q.empty()) {
            auto [i, j] = q.front();
            q.pop();
            for (auto & dir : dirs) {
                int x = i + dir[0], y = j + dir[1];
                if (x >= 0 && x < m && y >= 0 && y < n && result[x][y] == -1) {
                    result[x][y] = result[i][j] + 1;
                    q.emplace(x, y);
                }
            } 
        }
        return result;
    }
};