class Solution {
public:
    int findRadius(vector<int>& houses, vector<int>& heaters) {
        int result = 0;
        sort(heaters.begin(), heaters.end());
        for (auto & house : houses) {
            int temp_result = INT_MAX;
            for (auto & heater : heaters) {
                temp_result = min(temp_result, abs(house - heater));
                if (abs(house - heater) > temp_result) {
                    break;
                }
            }
            result = max(result, temp_result);
        }
        return result;
    }
};