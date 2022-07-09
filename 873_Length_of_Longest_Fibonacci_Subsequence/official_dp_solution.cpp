class Solution {
public:
    int lenLongestFibSubseq(vector<int>& arr) {
        int result = 0, n = arr.size();
        unordered_map<int, int> m;
        for (int i = 0; i < n; ++i) {
            m[arr[i]] = i;
        }   
        vector<vector<int>> dp(n, vector<int>(n, 0));
        for (int i = 2; i < n; ++i) {
            for (int j = i; j >= 0 && arr[j] * 2 > arr[i]; --j) {
                int k = -1;
                if (m.count(arr[i] - arr[j])) {
                    k = m[arr[i] - arr[j]];
                }
                if (k >= 0) {
                    dp[j][i] = max(dp[k][j] + 1, 3);
                }
                result = max(result, dp[j][i]);
            }
        }
        return result;
    }
};