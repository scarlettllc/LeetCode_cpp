class Solution {
public:
    vector<int> busiestServers(int k, vector<int>& arrival, vector<int>& load) {
        set<int> available;
        for (int i = 0; i < k; ++i) {
            available.insert(i);
        }
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> busy;
        vector<int> request_dealed(k, 0);
        int n = arrival.size();
        for (int i = 0; i < n; ++i) {
            int arrival_time = arrival[i];
            while (!busy.empty() && busy.top().first <= arrival_time) {
                available.insert(busy.top().second);
                busy.pop();
            }
            if (available.empty()) {
                continue;
            }
            auto p = available.lower_bound(i % k);
            if (p == available.end()) {
                p = available.begin();
            }
            busy.emplace(arrival_time + load[i], *p);
            request_dealed[*p] += 1;
            available.erase(p);
        }
        int max_requests = *max_element(request_dealed.begin(), request_dealed.end());
        vector<int> result;
        for (int i = 0; i < k; ++i) {
            if (request_dealed[i] == max_requests) {
                result.push_back(i);
            }
        }
        return result;
    }
};