class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        if (n == 1) {
            return {0};
        }
        map<int, set<int>> adjacents;
        for (auto & edge : edges) {
            adjacents[edge[0]].insert(edge[1]);
            adjacents[edge[1]].insert(edge[0]);
        }
        vector<int> parent(n, -1);
        int x = helper(0, parent, adjacents);
        int y = helper(x, parent, adjacents);
        parent[x] = -1;
        vector<int> path;
        while (y != -1) {
            path.push_back(y);
            y = parent[y];
        }
        int m = path.size();
        if (m % 2 == 0) {
            return {path[m / 2 - 1], path[m / 2]};
        } else {
            return {path[m / 2]};
        }
    } 
    int helper(int i, vector<int>& parent, map<int, set<int>> & adjacents) {
        int n = adjacents.size();
        vector<bool> visited(n, false);
        int node = -1;
        queue<int> q;
        q.emplace(i);
        visited[i] = true;
        while (!q.empty()) {
            int top = q.front();
            q.pop();
            node = top;
            for (auto & adj : adjacents[top]) {
                if (!visited[adj]) {
                    parent[adj] = top;
                    visited[adj] = true;
                    q.emplace(adj);
                }
            }
        }
        return node;
    }
};