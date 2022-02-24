class Solution {
public:
    vector<int> findBall(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<int> result(n, -1);
        for (int j = 0; j < n; ++j) {
            int current = j;
            int i = 0;
            for (; i < m; ++i) {
                if (current >= n || current < 0) {
                    break;
                }
                bool right = (grid[i][current] == 1);
                if (right) {
                    if (current == n - 1 || grid[i][current + 1] == -1) {
                        break;
                    }
                    ++current;
                } else {
                    if (current == 0 || grid[i][current - 1] == 1) {
                        break;
                    }
                    --current;
                }
            }
            if (i == m) {
                result[j] = current;
            }
        }
        return result;
    }
};