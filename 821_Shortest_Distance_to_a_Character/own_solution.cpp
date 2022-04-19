class Solution {
public:
    vector<int> shortestToChar(string s, char c) {
        int n = s.size();
        vector<int> result(n, INT_MAX);
        for (int i = 0; i < n; ++i) {
            if (s[i] == c) {
                for (int j = 0; j < n; ++j) {
                    result[j] = min(result[j], abs(i - j));
                }
            }
        }
        return result;
    }
};