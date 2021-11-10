class Solution {
public:
    int findPoisonedDuration(vector<int>& timeSeries, int duration) {
        int n = timeSeries.size();
        int result = duration;
        for (int i = 1; i < n; ++i) {
            if (timeSeries[i] < timeSeries[i - 1] + duration) {
                result += (timeSeries[i] - timeSeries[i - 1]);
            } else {
                result += duration;
            }
        }
        return result;
    }
};