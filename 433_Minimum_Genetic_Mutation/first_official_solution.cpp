class Solution {
public:
    int minMutation(string start, string end, vector<string>& bank) {
        if (start == end) {
            return 0;
        }
        unordered_set<string> cnt;
        for (auto & candidate : bank) {
            cnt.insert(candidate);
        }
        if (!cnt.count(end)) {
            return -1;
        }
        unordered_set<string> visited;
        queue<string> q;
        char keys[4] = {'A', 'C', 'G', 'T'};
        int step = 1;
        q.emplace(start);
        visited.insert(start);
        while (!q.empty()) {
            int sz = q.size();
            for (int i = 0; i < sz; ++i) {
                string top = q.front();
                q.pop();
                for (int j = 0; j < 8; ++j) {
                    for (int k = 0; k < 4; ++k) {
                        if (keys[k] != top[j]) {
                            string next = top;
                            next[j] = keys[k];
                            if (!visited.count(next) && cnt.count(next)) {
                                if (next == end) {
                                    return step;
                                }
                                q.emplace(next);
                                visited.insert(next);
                            }
                        }
                    }
                }
            }
            ++step;
        }
        return -1;
    }
};