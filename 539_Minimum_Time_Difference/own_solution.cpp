class Solution {
public:
    int findMinDifference(vector<string>& timePoints) {
        vector<int> timeline;
        int n = timePoints.size();
        for (int i = 0; i < n; ++i) {
            timeline.push_back(stoi(timePoints[i].substr(0, 2)) * 60 + stoi(timePoints[i].substr(3, 2)));
        }
        sort(timeline.begin(), timeline.end());
        int result = 24 * 60, m = timeline.size();
        for (int i = 1; i < m; ++i) {
            result = min(result, timeline[i] - timeline[i - 1]);
        }
        result = min(result, 24 * 60 + timeline[0] - timeline[timeline.size() - 1]);
        return result;
    }
};