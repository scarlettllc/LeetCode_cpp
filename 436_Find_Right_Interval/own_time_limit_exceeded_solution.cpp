class Solution {
public:
    vector<int> findRightInterval(vector<vector<int>>& intervals) {
        int n = intervals.size();
        vector<int> result;
        for (int i = 0; i < n; ++i) {
            int temp_result = -1, start = INT_MAX;
            for (int j = 0; j < n; ++j) {
                if (j == i) {
                    continue;
                }
                if (intervals[j][0] >= intervals[i][1] && intervals[j][0] < start) {
                    start = intervals[j][0];
                    temp_result = j;
                }
            }
            result.push_back(temp_result);
        }
        return result;
    }
};