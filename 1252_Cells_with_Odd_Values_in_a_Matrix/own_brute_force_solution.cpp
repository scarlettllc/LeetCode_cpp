class Solution {
public:
    int oddCells(int m, int n, vector<vector<int>>& indices) {
        vector<vector<int>> matrix(m, vector<int>(n, 0));
        for (auto & indice : indices) {
            for (int j = 0; j < n; ++j) {
                ++matrix[indice[0]][j];
            }
            for (int i = 0; i < m; ++i) {
                ++matrix[i][indice[1]];
            }
        }
        int result = 0;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (matrix[i][j] % 2 == 1) {
                    ++result;
                }
            }
        }
        return result;
    }
};