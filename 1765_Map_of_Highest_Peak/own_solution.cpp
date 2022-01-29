class Solution {
private:
    int m, n;
public:
    vector<vector<int>> highestPeak(vector<vector<int>>& isWater) {
        m = isWater.size(), n = isWater[0].size();
        vector<vector<int>> result(m, vector<int>(n, -1));
        bool flag = false;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (isWater[i][j] == 1) {
                    flag = true;
                    result[i][j] = 0;
                }
            }
        }
        if (!flag) {
            result[0][0] = 0;
        }
        vector<vector<bool>> visited(m, vector<bool>(n, false)); 
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                dfs(result, visited, i, j);
            }
        }
        visited.assign(m,vector<bool>(n, false));
        for (int i = m - 1; i >= 0; --i) {
            for (int j = n - 1; j >= 0; --j) {
                dfs(result, visited, i, j);
            }
        }
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                cout << result[i][j] << " ";
            }
            cout << endl;
        }
        return result;
    }
    void dfs(vector<vector<int>>& result, vector<vector<bool>>& visited, int i, int j) {
        if (i < 0 || i >= m || j < 0 || j >= n) {
            return;
        }
        if (visited[i][j]) {
            return;
        }
        if (result[i][j] != -1) {
            visited[i][j] = true;
            change_value(result[i][j], result, i + 1, j);
            change_value(result[i][j], result, i - 1, j);
            change_value(result[i][j], result, i, j + 1);
            change_value(result[i][j], result, i, j - 1);
        }
    }
    void change_value(int base, vector<vector<int>>& result, int i, int j) {
        if (i < 0 || i >= m || j < 0 || j >= n) {
            return;
        }
        if (result[i][j] == -1) {
            result[i][j] = base + 1;
        } else {
            result[i][j] = min(base + 1, result[i][j]);
        }
    }
};