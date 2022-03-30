class Solution {
public:
    vector<int> busiestServers(int k, vector<int>& arrival, vector<int>& load) {
        vector<int> next_freetime(k, 0);
        vector<int> request_dealed(k, 0);
        int n = arrival.size();
        for (int i = 0; i < n; ++i) {
            int start_server = i % k;
            int arrival_time = arrival[i];
            for (int j = start_server; j < start_server + k; ++j) {
                int candidate_server = j % k;
                if (next_freetime[candidate_server] <= arrival_time) {
                    next_freetime[candidate_server] = arrival_time + load[i];
                    request_dealed[candidate_server] += 1;
                    break;
                }
            }
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