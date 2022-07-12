class Solution {
public:
    int oddCells(int m, int n, vector<vector<int>>& indices) {
        vector<int> rows(m, 0), cols(n, 0);
        for (auto & indice : indices) {
            ++rows[indice[0]];
            ++cols[indice[1]];
        }
        int result = 0;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if ((rows[i] + cols[j]) & 1) {
                    ++result;
                }
            }
        }
        return result;
    }
};