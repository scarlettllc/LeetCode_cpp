class Solution {
public:
    int maxIncreaseKeepingSkyline(vector<vector<int>>& grid) {
        vector<int> max_rows;
        for (int i = 0; i < grid.size(); ++i) {
            int temp = 0;
            for (int j = 0; j < grid[i].size(); ++j) {
                if (grid[i][j] > temp) {
                    temp = grid[i][j];
                }
            }
            max_rows.push_back(temp);
        }
        vector<int> max_columns;
        for (int j = 0; j < grid[0].size(); ++j) {
            int temp = 0;
            for (int i = 0; i < grid.size(); ++i) {
                if (grid[i][j] > temp) {
                    temp = grid[i][j];
                }
            }
            max_columns.push_back(temp);
        }
        int result = 0;
        for (int i = 0; i < grid.size(); ++i) {
            for (int j = 0; j < grid[0].size(); ++j) {
                result += min(max_rows[i], max_columns[j]) - grid[i][j];
            }
        } 
        return result;
    }
};