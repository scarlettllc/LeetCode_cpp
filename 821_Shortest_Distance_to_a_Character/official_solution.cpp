class Solution {
public:
    vector<int> shortestToChar(string s, char c) {
        int n = s.size(), idx;
        vector<int> result(n, INT_MAX);
        for (int i = 0, idx = -n; i < n; ++i) {
            if (s[i] == c) {
                idx = i;
            }
            result[i] = min(result[i], i - idx);
        }
        for (int i = n - 1, idx = 2 * n; i >= 0; --i) {
            if (s[i] == c) {
                idx = i;
            }
            result[i] = min(result[i], idx - i);
        }
        return result;
    }
};