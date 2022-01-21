class Solution {
public:
    int minJumps(vector<int>& arr) {
        if (arr.size() == 1) {
            return 0;
        }
        int n = arr.size();
        if (arr[n - 1] == arr[0]) {
            return 1;
        }
        unordered_map<int, vector<int>> value2idx;
        for (int i = 0; i < n; ++i) {
            value2idx[arr[i]].push_back(i);
        }
        unordered_set<int> visited_index;
        queue<pair<int, int>> q;
        q.emplace(0, 0);
        visited_index.emplace(0);
        while (!q.empty()) {
            auto [idx, step] = q.front();
            q.pop();
            if (idx == n - 1) {
                return step;
            }
            int value = arr[idx];
            ++step;
            if (value2idx.count(value)) {
                for (auto & i : value2idx[value]) {
                    if (!visited_index.count(i)) {
                        visited_index.emplace(i);
                        q.emplace(i, step);
                    }
                }
                value2idx.erase(value);
            }
            if (!visited_index.count(idx + 1) && idx + 1 < n) {
                visited_index.emplace(idx + 1);
                q.emplace(idx + 1, step);
            }
            if (!visited_index.count(idx - 1) && idx - 1 >= 0) {
                visited_index.emplace(idx - 1);
                q.emplace(idx - 1, step);
            }
        }
        return -1;
    }
};