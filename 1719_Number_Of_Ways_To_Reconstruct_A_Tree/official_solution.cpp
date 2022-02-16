class Solution {
public:
    int checkWays(vector<vector<int>>& pairs) {
        unordered_map<int, unordered_set<int>> adj;
        for (auto & pair : pairs) {
            adj[pair[0]].emplace(pair[1]);
            adj[pair[1]].emplace(pair[0]);
        }
        int root = -1;
        for (auto & [node, neighbors] : adj) {
            if (neighbors.size() == adj.size() - 1) {
                root = node;
                break;
            }
        }
        if (root == -1) {
            return 0;
        }
        int result = 1;
        for (auto & [node, neighbors] : adj) {
            if (node == root) {
                continue;
            }
            int currDegree = neighbors.size();
            int parent = -1;
            int parentDegree = INT_MAX;
            for (auto & neighbor : neighbors) {
                if (adj[neighbor].size() < parentDegree && adj[neighbor].size() >= currDegree) {
                    parent = neighbor;
                    parentDegree = adj[neighbor].size();
                }
            }
            if (parent == -1) {
                return 0;
            }
            for (auto & neighbor : neighbors) {
                if (neighbor == parent) {
                    continue;
                }
                if (!adj[parent].count(neighbor)) {
                    return 0;
                }
            }
            if (parentDegree == currDegree) {
                result = 2;
            }
        }
        return result;
    }
};