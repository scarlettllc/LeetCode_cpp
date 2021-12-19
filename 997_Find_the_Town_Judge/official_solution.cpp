class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        vector<int> inDegrees(n + 1, 0);
        vector<int> outDegrees(n + 1, 0);
        for (auto & edge : trust) {
            ++inDegrees[edge[1]];
            ++outDegrees[edge[0]];
        }
        for (int i = 1; i <= n; ++i) {
            if (inDegrees[i] == n - 1 && outDegrees[i] == 0) {
                return i;
            }
        }
        return -1;
    }
};