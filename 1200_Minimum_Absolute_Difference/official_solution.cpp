class Solution {
public:
    vector<vector<int>> minimumAbsDifference(vector<int>& arr) {
        sort(arr.begin(), arr.end());
        int min_diff = INT_MAX, n = arr.size();
        vector<vector<int>> result;
        for (int i = 0; i < n - 1; ++i) {
            if (arr[i + 1] - arr[i] < min_diff) {
                result = {{arr[i], arr[i + 1]}};
                min_diff = arr[i + 1] - arr[i];
            } else if(arr[i + 1] - arr[i] == min_diff){
                result.push_back({arr[i], arr[i + 1]});
            }
        }
        return result;
    }
};