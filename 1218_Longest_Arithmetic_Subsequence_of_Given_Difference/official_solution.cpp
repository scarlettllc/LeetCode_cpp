class Solution {
public:
    int longestSubsequence(vector<int>& arr, int difference) {
        int result = 0;
        unordered_map<int, int> dp;
        for (auto & v : arr) {
            dp[v] = dp[v - difference] + 1;
            result = max(result, dp[v]);
        }
        return result;
    }
};