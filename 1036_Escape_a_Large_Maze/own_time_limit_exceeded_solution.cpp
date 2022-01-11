class Solution {
public:
    bool isEscapePossible(vector<vector<int>>& blocked, vector<int>& source, vector<int>& target) {
        vector<vector<int>> visited;
        visited.push_back(source);
        return dfs(blocked, source, target, visited);
    }
    bool dfs(vector<vector<int>>& blocked, vector<int>& point, vector<int>& target, vector<vector<int>>& visited) {
        if (point == target) {
            return true;
        }
        vector<vector<int>> candidates{{point[0] - 1, point[1]}, {point[0] + 1, point[1]}, {point[0], point[1] -1}, {point[0], point[1] + 1}};
        for (auto & candidate : candidates) {
            if (candidate[0] < 0 || candidate[0] >= 1000000 || candidate[1] < 0 || candidate[1] >= 1000000) {
                continue;
            }
            if (find(blocked.begin(), blocked.end(), candidate) != blocked.end()) {
                continue;
            }
            if (find(visited.begin(), visited.end(), candidate) != visited.end()) {
                continue;
            }
            visited.push_back(candidate);
            if (dfs(blocked, candidate, target, visited)) {
                return true;
            }
        }
        return false;
    }
};