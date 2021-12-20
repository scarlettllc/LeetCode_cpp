class Solution {
public:
    int findRadius(vector<int>& houses, vector<int>& heaters) {
        int result = 0;
        sort(heaters.begin(), heaters.end());
        for (auto & house : houses) {
            int temp_result = INT_MAX;
            int j = upper_bound(heaters.begin(), heaters.end(), house) - heaters.begin();
            int i = j - 1;
            if (j < heaters.size()) {
                temp_result = min(temp_result, heaters[j] - house);
            }
            if (i >= 0) {
                temp_result = min(temp_result, house - heaters[i]);
            }
            result = max(result, temp_result);
        }
        return result;
    }
};