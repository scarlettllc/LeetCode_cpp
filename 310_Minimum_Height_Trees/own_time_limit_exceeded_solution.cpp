class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        map<int, set<int>> adjacents;
        for (auto & edge : edges) {
            adjacents[edge[0]].insert(edge[1]);
            adjacents[edge[1]].insert(edge[0]);
        }
        vector<vector<int>> distances(n, vector<int>(n, -1));
        for (int i = 0; i < n; ++i) {
            get_distances(i, distances, adjacents);
        }
        vector<int> heights(n, 0);
        for (int i = 0; i < n; ++i) {
            heights[i] = *max_element(distances[i].begin(), distances[i].end());
        }
        int min_height = *min_element(heights.begin(), heights.end());
        vector<int> result;
        for (int i = 0; i < n; ++i) {
            if (heights[i] == min_height) {
                result.push_back(i);
            }
        }
        return result;
    }
    void get_distances(int i, vector<vector<int>> & distances, map<int, set<int>>& adjacents) {
        queue<int> q;
        q.emplace(i);
        distances[i][i] = 0;
        while (!q.empty()) {
            int top = q.front();
            q.pop();
            for (auto & adj : adjacents[top]) {
                if (distances[i][adj] == -1) {
                    q.emplace(adj);
                    distances[i][adj] = distances[i][top] + 1;
                }
            }
        }
    }
};