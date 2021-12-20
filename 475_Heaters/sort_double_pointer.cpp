class Solution {
public:
    int findRadius(vector<int>& houses, vector<int>& heaters) {
        int result = 0;
        sort(houses.begin(), houses.end());
        sort(heaters.begin(), heaters.end());
        for (int i = 0, j = 0; i < houses.size(); ++i) {
            while (j < heaters.size() - 1 && abs(houses[i] - heaters[j]) >= abs(houses[i] - heaters[j + 1])) {
                ++j;
            }
            result = max(result, abs(houses[i] - heaters[j]));
        }
        return result;
    }
};