class Solution {
public:
    vector<int> luckyNumbers (vector<vector<int>>& matrix) {
        int result = INT_MIN, idx = 0;
        for (auto & row : matrix) {
            auto it = min_element(row.begin(), row.end());
            if (*it > result) {
                result = *it;
                idx = it - row.begin();
            }
        }
        for (auto & row : matrix) {
            if (row[idx] > result) {
                return {};
            }
        }
        return {result};
    }
};