class Solution {
public:
    vector<vector<int>> minimumAbsDifference(vector<int>& arr) {
        sort(arr.begin(), arr.end());
        int min_diff = INT_MAX, n = arr.size();
        for (int i = 0; i < n - 1; ++i) {
            min_diff = min(min_diff, arr[i + 1] - arr[i]);
        }
        vector<vector<int>> result;
        for (int i = 0; i < n - 1; ++i) {
            if (arr[i + 1] - arr[i] == min_diff) {
                result.push_back({arr[i], arr[i + 1]});
            }
        }
        return result;
    }
};