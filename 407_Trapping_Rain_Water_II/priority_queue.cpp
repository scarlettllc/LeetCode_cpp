class Solution {
public:
    int trapRainWater(vector<vector<int>>& heightMap) {
        int m = heightMap.size(), n = heightMap[0].size();
        if (m <= 2 || n <= 2) {
            return 0;
        }
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (i == 0 || i == m - 1 || j == 0 || j == n - 1) {
                    pq.push(make_pair(heightMap[i][j], i * n + j));
                    visited[i][j] = true;
                }
            }
        }
        int dirs[] = {-1, 0, 1, 0, -1};
        int result = 0;
        while (!pq.empty()) {
            pair<int, int> cur = pq.top();
            pq.pop();
            for (int i = 0; i < 4; ++i) {
                int nx = cur.second / n + dirs[i];
                int ny = cur.second % n + dirs[i + 1];
                if (nx >= 0 && nx < m && ny >= 0 && ny < n && !visited[nx][ny]) {
                    if (heightMap[nx][ny] < cur.first) {
                        result += (cur.first - heightMap[nx][ny]);
                    }
                    visited[nx][ny] = true;
                    pq.push(make_pair(max(heightMap[nx][ny], cur.first), nx * n + ny));
                }
            }
        }
        return result;
    }
};