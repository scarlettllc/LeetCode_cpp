class Solution {
public:
    vector<int> loudAndRich(vector<vector<int>>& richer, vector<int>& quiet) {
        int n = quiet.size();
        vector<int> result(n, -1);
        vector<vector<int>> graph(n);
        for (auto & rich : richer) {
            graph[rich[1]].push_back(rich[0]);
        }
        for (int i = 0; i < n; ++i) {
            result[i] = dfs(result, graph, quiet, i);
        }
        return result;
    }
    int dfs(vector<int>& result, vector<vector<int>>& graph, vector<int>& quiet, int i) {
        if(result[i] != -1) {
            return result[i];
        } 
        result[i] = i;
        for (int y : graph[i]) {
            int temp = dfs(result, graph, quiet, y);
            if (quiet[temp] < quiet[result[i]]) {
                result[i] = temp;
            }
        }
        return result[i];
    }
};