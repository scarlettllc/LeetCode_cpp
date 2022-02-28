class Solution {
public:
    int maximumRequests(int n, vector<vector<int>>& requests) {
        int result = 0, m = requests.size();
        vector<int> delta(n);
        for (unsigned int mask = 0; mask < (1 << m); ++mask) {
            int count = __builtin_popcount(mask);
            if (count < result) {
                continue;
            }
            fill(delta.begin(), delta.end(), 0);
            for (int i = 0; i < m; ++i) {
                if (mask & (1 << i)) {
                    ++delta[requests[i][0]];
                    --delta[requests[i][1]];
                }
            }
            if (std::all_of(delta.begin(), delta.end(), [](int x){ return x == 0; }))  { 
                result = count;
            } 
        }
        return result;
    }
};