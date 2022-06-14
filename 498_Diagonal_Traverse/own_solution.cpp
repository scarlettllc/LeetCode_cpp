class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
        vector<int> result;
        int m = mat.size(), n = mat[0].size();
        for (int s = 0; s < m + n - 1; ++s) {
            if (s % 2 == 0) {
                for (int i = min(s, m - 1); i >= max(0, s - n + 1); --i) {
                    result.push_back(mat[i][s - i]);
                }
            } else {
                for (int i = max(0, s - n + 1); i <= min(s, m - 1); ++i) {
                    result.push_back(mat[i][s - i]);
                }
            }
        }
        return result;
    }
};