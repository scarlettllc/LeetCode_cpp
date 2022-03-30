class Solution {
public:
    vector<int> busiestServers(int k, vector<int>& arrival, vector<int>& load) {
        set<int> available;
        for (int i = 0; i < k; ++i) {
            available.insert(i);
        }
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> busy;
        vector<int> requests(k, 0);
        int n = arrival.size();
        for (int i = 0; i < n; ++i) {
            int arrival_time = arrival[i];
            while (!busy.empty() && busy.top().first <= arrival_time) {
                available.insert(busy.top().second);
                busy.pop();
            }
            if (available.size() == 0) {
                continue;
            }
            auto p = available.lower_bound(i % k);
            if (p == available.end()) {
                p = available.begin();
            }
            ++requests[*p];
            busy.emplace(arrival_time + load[i], *p);
            available.erase(p);
        }
        vector<int> result;
        int max_request = *max_element(requests.begin(), requests.end());
        for (int i = 0; i < k; ++i) {
            if (requests[i] == max_request) {
                result.push_back(i);
            }
        }
        return result;
    }
};