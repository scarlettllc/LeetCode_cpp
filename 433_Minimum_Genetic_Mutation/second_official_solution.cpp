class Solution {
public:
    int minMutation(string start, string end, vector<string>& bank) {
        if (start == end) {
            return 0;
        }
        int m = start.size(), n = bank.size(), end_index = -1;
        vector<vector<int>> adj(n);
        for (int i = 0; i < n; ++i) {
            if (end == bank[i]) {
                end_index = i;
            }
            for (int j = i + 1; j < n; ++j) {
                int mutations = 0;
                for (int k = 0; k < m; ++k) {
                    if (bank[i][k] != bank[j][k]) {
                        ++mutations;
                    }
                    if (mutations > 1) {
                        break;
                    }
                }
                if (mutations == 1) {
                    adj[i].push_back(j);
                    adj[j].push_back(i);
                }
            }
        }
        if (end_index == -1) {
            return -1;
        }
        queue<int> q;
        vector<bool> visited(n, false);
        for (int i = 0; i < n; ++i) {
            int mutations = 0;
            for (int k = 0; k < m; ++k) {
                if (start[k] != bank[i][k]) {
                    ++mutations;
                }
                if (mutations > 1) {
                    break;
                }
            }
            if (mutations == 1) {
                q.emplace(i);
                visited[i] = true;
            }
        } 
        int step = 1;
        while (!q.empty()) {
            int sz = q.size();
            for (int i = 0; i < sz; ++i) {
                int top = q.front();
                q.pop();
                if (top == end_index) {
                    return step;
                } 
                for (auto & next : adj[top]) {
                    if (visited[next]) {
                        continue;
                    }
                    q.emplace(next);
                    visited[next] = true;
                }
            }
            ++step;
        }
        return -1;
    }
};