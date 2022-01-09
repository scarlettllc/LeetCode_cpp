class Solution {
public:
    char slowestKey(vector<int>& releaseTimes, string keysPressed) {
        char result = keysPressed[0];
        int max_time = releaseTimes[0];
        int n = releaseTimes.size();
        for (int i = 1; i < n; ++i) {
            if (releaseTimes[i] - releaseTimes[i - 1] > max_time || (releaseTimes[i] - releaseTimes[i - 1] == max_time && keysPressed[i] > result)) {
                max_time = releaseTimes[i] - releaseTimes[i - 1];
                result = keysPressed[i];
            }
        }
        return result;
    }
};