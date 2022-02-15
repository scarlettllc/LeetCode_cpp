class Solution {
public:
    vector<int> luckyNumbers (vector<vector<int>>& matrix) {
        vector<int> candidates;
        for (auto & row : matrix) {
            candidates.push_back(min_element(row.begin(), row.end()) - row.begin());
        }
        vector<int> result;
        for (int i = 0; i < matrix.size(); ++i) {
            int row_candidate = matrix[i][candidates[i]];
            bool flag = true;
            for (int k = 0; k < matrix.size(); ++k) {
                if (k == i) {
                    continue;
                }
                if (matrix[k][candidates[i]] > row_candidate) {
                    flag = false;
                    break;
                }
            }
            if (flag) {
                result.push_back(row_candidate);
            }
        }
        return result;
    }
};