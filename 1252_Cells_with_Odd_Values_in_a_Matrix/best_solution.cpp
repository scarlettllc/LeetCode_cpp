class Solution {
public:
    int oddCells(int m, int n, vector<vector<int>>& indices) {
        vector<int> rows(m, 0), cols(n, 0);
        for (auto & indice : indices) {
            ++rows[indice[0]];
            ++cols[indice[1]];
        }
        int result = 0, oddx = 0, oddy = 0;
        for (int i = 0; i < m; ++i) {
            if (rows[i] & 1) {
                ++oddx;
            }
        }
        for (int j = 0; j < n; ++j) {
            if (cols[j] & 1) {
                ++oddy;
            }
        }
        return oddx * (n - oddy) + oddy * (m - oddx);
    }
};