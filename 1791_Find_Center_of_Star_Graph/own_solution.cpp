class Solution {
public:
    int findCenter(vector<vector<int>>& edges) {
        unordered_map<int, unordered_set<int>> adj;
        for (auto & edge : edges) {
            adj[edge[0]].emplace(edge[1]);
            adj[edge[1]].emplace(edge[0]);
        }
        for (auto & [node, neighbors] : adj) {
            if (neighbors.size() == adj.size() - 1) {
                return node;
            }
        }
        return 0;
    }
};