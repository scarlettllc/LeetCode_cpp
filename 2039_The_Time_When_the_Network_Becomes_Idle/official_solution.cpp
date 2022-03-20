class Solution {
public:
    int networkBecomesIdle(vector<vector<int>>& edges, vector<int>& patience) {
        int n = patience.size();
        vector<int> distances(n, -1);
        map<int, set<int>> adjacents;
        for (int i = 0; i < edges.size(); ++i) {
            adjacents[edges[i][0]].insert(edges[i][1]);
            adjacents[edges[i][1]].insert(edges[i][0]);
        } 
        queue<int> q;
        q.emplace(0);
        distances[0] = 0;
        while (!q.empty()) {
            int top = q.front();
            q.pop();
            for (auto & adj : adjacents[top]) {
                if (distances[adj] == -1) {
                    distances[adj] = distances[top] + 1;
                    q.emplace(adj);
                }
            }
        }
        int result = 0;
        for (int i = 1; i < n; ++i) {
            if (patience[i] >= 2 * distances[i]) {
                result = max(result, 2 * distances[i] + 1);
            } else {
                result = max(result, patience[i] * ((2 * distances[i] - 1) / patience[i]) + 2 * distances[i] + 1);
            }
        }
        return result;
    }
};