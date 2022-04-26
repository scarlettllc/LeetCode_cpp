class Solution {
public:
    int projectionArea(vector<vector<int>>& grid) {
        int s1 = 0, s2 = 0, s3 = 0, n = grid.size();
        for (int i = 0; i < n; ++i) {
            int temp1 = 0, temp2 = 0;
            for (int j = 0; j < n; ++j) {
                s1 += grid[i][j] != 0 ? 1 : 0;
                temp1 = max(temp1, grid[i][j]);
                temp2 = max(temp2, grid[j][i]);
            }
            s2 += temp1;
            s3 += temp2;
        }
        return s1 + s2 + s3;
    }
};